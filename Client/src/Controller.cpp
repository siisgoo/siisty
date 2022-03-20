#include "Controller.hpp"
#include "./ui_Controller.h"

#include <QTimer>
#include <qnamespace.h>

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
        _notifier = new FloatNotifier(
                this,
                QMargins(0, 0, 2, ui->statusbar->size().height() + 2),
                {120, 40},
                -1,
                3000,
                FloatNotifier::StackAbove);
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
    Login * login = new Login(this);

    connect(login, SIGNAL(tryLogin(ConnectSettings)), this, SLOT(tryLogin(ConnectSettings)), Qt::SingleShotConnection);

    login->show();
    if (login->exec()) {

    }
    delete login;
}

void
userInterface::recivedMessage(iiNPack::Header, QByteArray)
{

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

    connect(&_service, SIGNAL(errorOccurred(QAbstractSocket::SocketError)),
            this, SLOT(on_connectError(QAbstractSocket::SocketError)), Qt::SingleShotConnection);

    if (cs.protocol > 0) {
        connect(&_service, SIGNAL(encrypted()), this, SLOT(on_conneted()));
        _service.connectToHostEncrypted(cs.host.toString(), cs.port);
    } else {
        connect(&_service, SIGNAL(connected()), this, SLOT(on_conneted()));
        _service.connectToHost(cs.host, cs.port);
    }
}

void
userInterface::on_conneted()
{
    connect(&_service, SIGNAL(loginSuccess(QString, int, int)), this,
            SLOT(on_logined()), Qt::SingleShotConnection);
    _service.login(_conn_s.login, _conn_s.password);
}

void
userInterface::on_connectError(QAbstractSocket::SocketError)
{
    on_login_failed();
}

void
userInterface::on_logined()
{
    _notifier->setItemPropery(_login_puid, "title", "Logined");
    QTimer::singleShot(2000, [this]() {
        _notifier->setItemPropery(_login_puid, "forseComplete", NotifyItem::NotifySuccess);
    });
    ui->actionLogin->setEnabled(false);
    ui->actionLogout->setEnabled(true);
}

void
userInterface::on_login_failed()
{
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
