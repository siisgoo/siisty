#include "Controller.hpp"
#include "./ui_Controller.h"

#include <QTimer>
#include <qnamespace.h>
#include <qssl.h>

userInterface::userInterface(const Settings& settings, QWidget* _parent)
    : QMainWindow(_parent),
    ui(new Ui::Controller),
        _settings(settings),
        _log(Trace, "siisty-Client", settings.logDir, nullptr)
{
    ui->setupUi(this);

    connect(ui->actionLogin,  SIGNAL(triggered()), this, SLOT(showLogin()));
    connect(ui->actionLogout, SIGNAL(triggered()), this, SLOT(on_actionLogoutTriggered()));

    ui->page_path_layout->setAlignment(Qt::AlignLeft);

    {
        _notifier = new NotifyManager(
                this,
                QMargins(0, 0, 2, ui->statusbar->size().height() + 2),
                {120, 40},
                -1,
                NotifyManager::StackAbove);
        connect(this, SIGNAL(resized(QResizeEvent*)), _notifier, SIGNAL(windowResized(QResizeEvent*)));
        connect(this,
                SIGNAL(createNotifyItem(NotifyItemFactory *, int&)),
                _notifier,
                SLOT(createNotifyItem(NotifyItemFactory *, int&)));
        connect(this,
                SIGNAL(setNotifyItemPropery(int, const QByteArray &, const QVariant &)),
                _notifier,
                SLOT(setItemPropery(int, const QByteArray &, const QVariant &)));
    }

    {
        connect(this, SIGNAL(send_to_log(QString, int)), &_log, SLOT(logMessage(QString, int)));
        _log.moveToThread(&_loggingThread);
    }

    {
        connect(&_service, SIGNAL(logMessage(QString, int)), this, SLOT(logMessage(QString, int)));
    }

    setupPages();

    _npf = new NotifyProgressItemFactory;
    _nmf = new NotifyMsgItemFactory;

    // add check if saved auth data
    QTimer::singleShot(100, [this](){ showLogin(); });

    _loggingThread.start();
}

userInterface::~userInterface()
{
    _serviceThread.quit();
    _loggingThread.quit();

    _serviceThread.wait();
    _loggingThread.wait();

    delete _npf;
}

void
userInterface::setupPages()
{
    PagesManager::addRoot("Empty", new QWidget(), 0);

    /* changePage("Main"); */
}

void
userInterface::changePage(QString page)
{
    // todo
    // clear current path
    QLayoutItem * itm;
    while ((itm = ui->page_path_layout->takeAt(0)) != nullptr) {
        delete itm->widget();
        delete itm;
    }

    QVector<QString> path = PagesManager::getPagePath(page);
    for (auto node : path) {
        QWidget * lbl = new QLabel("->", ui->page_path_frame);
        lbl->setFont(QFont("Iosevka", 9));
        lbl->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        ui->page_path_layout->addWidget(lbl);
        ClickableLabel * clbl = new ClickableLabel(node, ui->page_path_frame);
        clbl->setFont(QFont("Sans", 9));
        clbl->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        clbl->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        clbl->setStyleSheet("color: #b78620");
        connect(clbl, SIGNAL(clicked()), this, SLOT(on_pathNodeClicked()));
        ui->page_path_layout->addWidget(clbl);
    }

    ui->page_view->setCurrentWidget(PagesManager::getPage(page));
    int nav = PagesManager::getPageNav(page);
    if (nav) {
        ui->NavPages->show();
        ui->NavPages->setCurrentIndex(PagesManager::getPageNav(page));
    } else {
        ui->NavPages->hide();
    }
}

void
userInterface::on_pathNodeClicked()
{
    ClickableLabel * lbl = dynamic_cast<ClickableLabel*>(sender());
    QString txt = lbl->text();
    changePage(txt);
}

void
userInterface::resizeEvent(QResizeEvent * e)
{
    e->accept();
    Q_EMIT resized(e);
}

void
userInterface::showLogin()
{
    changePage("Empty");
    readAuth();
    Login * login = new Login(_conn_s, this);

    connect(login, SIGNAL(tryLogin(ConnectSettings)), this, SLOT(tryLogin(ConnectSettings)), Qt::SingleShotConnection);

    login->show();
    if (login->exec()) {

    }
    delete login;
}

void
userInterface::saveAuth()
{
    // TODO add optional save pass
    QFile authf("./auth.json");
    authf.open(QIODevice::WriteOnly);
    if (!authf.permissions().testFlag(QFile::Permission::WriteOwner)) {
        int msg_pid;
        _nmf->setTitle("Cannot save auth");
        _nmf->setMsg("No write permission");
        _nmf->setCompleteTimeout(3000);
        _notifier->createNotifyItem(_nmf, msg_pid);
        return;
    }
    authf.setPermissions(QFile::Permissions::enum_type::ReadOwner | QFile::Permissions::enum_type::WriteOwner);
    QJsonDocument d(QJsonObject{
        { "login", (_conn_s.rememberLogin ? _conn_s.login : "") },
        { "password", (_conn_s.rememberPassword ? _conn_s.password : "") },
        { "host", _conn_s.host.toString() },
        { "port", (int)_conn_s.port },
        { "encryption", (int)_conn_s.protocol },
        { "rememberLogin", _conn_s.rememberLogin },
        { "rememberPassword", _conn_s.rememberPassword }
    });
    authf.write(d.toJson());
}

void
userInterface::readAuth()
{
    QFile authf("./auth.json");
    authf.open(QIODevice::ReadOnly);

    QJsonParseError err;
    if (!authf.permissions().testFlag(QFile::Permission::ReadOwner)) {
        int msg_pid;
        _nmf->setTitle("Cannot read auth");
        _nmf->setMsg("No read permission");
        _nmf->setCompleteTimeout(3000);
        _notifier->createNotifyItem(_nmf, msg_pid);
        return;
    }
    QJsonDocument d = QJsonDocument::fromJson(authf.readAll(), &err);

    if (err.error != QJsonParseError::NoError || d.isNull() || !d.isObject()) {
        _conn_s.host = QHostAddress("127.0.0.1");
        _conn_s.port = 2142;
        _conn_s.login = "";
        _conn_s.password = "";
        _conn_s.protocol = (int)QSsl::UnknownProtocol;
        _conn_s.rememberLogin = true;
        _conn_s.rememberPassword = false;
        return;
    }

    QJsonObject obj = d.object();
    _conn_s.host = QHostAddress(obj["host"].toString());
    _conn_s.port = obj["port"].toInteger();
    _conn_s.protocol = obj["encryption"].toInt();
    _conn_s.login = obj["login"].toString();
    _conn_s.password = obj["password"].toString();
    _conn_s.rememberLogin = obj["rememberLogin"].toBool();
    _conn_s.rememberPassword = obj["rememberPassword"].toBool();
}

void
userInterface::tryLogin(ConnectSettings cs)
{
    _npf->setTitle("Connecting to host");
    _npf->setCompleteTimeout(2000);
    _npf->setExitOnCompleted(false);
    _npf->setMaximum(0);
    _notifier->createNotifyItem(_npf, _login_puid);
    _notifier->setItemPropery(_login_puid, "progress", 0);

    _conn_s = cs;
    saveAuth();

    connect(&_service, SIGNAL(loginFailed(int, QString)),
            this, SLOT(on_login_failed(int, QString)),
            Qt::SingleShotConnection);

    connect(&_service, SIGNAL(disconnected()),
            this, SLOT(on_disconnetWhenLogin()),
            Qt::SingleShotConnection);

    if (cs.protocol > 0) {
        connect(&_service, SIGNAL(encrypted()), this, SLOT(on_conneted()), Qt::SingleShotConnection);
        _service.connectToHostEncrypted(cs.host.toString(), cs.port);
    } else {
        connect(&_service, SIGNAL(connected()), this, SLOT(on_conneted()), Qt::SingleShotConnection);
        _service.connectToHost(cs.host, cs.port);
    }
}

void
userInterface::on_conneted()
{
    _notifier->setItemPropery(_login_puid, "title", "Trying sing up");
    connect(&_service, SIGNAL(loginSuccess(QString, int, int)), this,
            SLOT(on_logined(QString, int, int)), Qt::SingleShotConnection);
    _service.login(_conn_s.login, _conn_s.password);
}

void
userInterface::on_disconnetWhenLogin()
{
    _notifier->setItemPropery(_login_puid, "title", "Host not avalible"); //TODO...
    QTimer::singleShot(2000, [this]() {
        _notifier->setItemPropery(_login_puid, "forseComplete", NotifyItem::NotifySuccess);
    });
}

void
userInterface::on_logined(QString name, int role, int id)
{
    _notifier->setItemPropery(_login_puid, "title", "Logined");
    QTimer::singleShot(2000, [this]() {
        _notifier->setItemPropery(_login_puid, "forseComplete", NotifyItem::NotifySuccess);
    });
    ui->actionLogin->setEnabled(false);
    ui->actionLogout->setEnabled(true);
}

void
userInterface::on_login_failed(int err, QString str)
{
    Q_EMIT logMessage(
        "Login failed. Error code: " + QString::number(err) + " Reason: " + str, Error);
    _notifier->setItemPropery(_login_puid, "title", "Login failed");
    _notifier->setItemPropery(_login_puid, "maxProgress", 1);
    _notifier->setItemPropery(_login_puid, "progress", 1);
    QTimer::singleShot(2000, [this]() {
        _notifier->setItemPropery(_login_puid, "forseComplete", NotifyItem::NotifySuccess);
    });
    ui->actionLogin->setEnabled(true);
    ui->actionLogout->setEnabled(false);
    showLogin();
}

void
userInterface::on_logouted()
{
    ui->actionLogin->setEnabled(true);
    ui->actionLogout->setEnabled(false);
    showLogin();
}

void
userInterface::on_actionLogoutTriggered()
{
    _service.disconnectFromHost();
    // update ui
}

void
userInterface::logMessage(QString _message, int level)
{
    qDebug() << _message;

    Q_EMIT send_to_log(_message, level);
}
