#include "Controller.hpp"
#include "./ui_Controller.h"

#include <QTimer>

userInterface::userInterface(const Settings& settings, QWidget* _parent)
    : QMainWindow(_parent),
    ui(new Ui::Controller),
        _settings(settings),
        _log(Trace, "siisty-Client", settings.logDir, nullptr)
{
    ui->setupUi(this);

    connect(ui->actionLogin,  SIGNAL(triggered()), this, SLOT(showLogin()));
    connect(ui->actionLogout, SIGNAL(triggered()), this, SLOT(on_actionLogoutTriggered()));

    _notifier = new FloatNotifier(this, QMargins(0, 0, 2, ui->statusbar->size().height() + 2));
    connect(this, SIGNAL(resized(QResizeEvent*)), _notifier, SIGNAL(windowResized(QResizeEvent*)));
    connect(this, SIGNAL(setProgress(int,int,QString,int)), _notifier, SIGNAL(setProgress(int, int, QString, int)));

    setupLogger();
    setupService();
    setupPages();

    // add check if saved auth data
    QTimer::singleShot(100, [this](){ showLogin(); });
}

userInterface::~userInterface()
{
    _serviceThread.quit();
    _loggingThread.quit();

    _serviceThread.wait();
    _loggingThread.wait();
}

void
userInterface::setupLogger()
{
    connect(this, SIGNAL(send_to_log(QString, int)), &_log, SLOT(logMessage(QString, int)));

    _log.moveToThread(&_loggingThread);
    _loggingThread.start();
}

void
userInterface::setupService()
{
    connect(&_service, SIGNAL(logMessage(QString, int)), this, SLOT(logMessage(QString, int)));
    connect(&_service, SIGNAL(recivedMessage(iiNPack::Header, QByteArray)), this, SLOT(recivedMessage(iiNPack::Header, QByteArray)));

    if (_settings.useSsl) {
        connect(&_service, SIGNAL(encrypted()), this, SLOT(on_connetedToServer()));
    } else {
        connect(&_service, SIGNAL(connected()), this, SLOT(on_connetedToServer()));
    }

    connect(&_service, SIGNAL(disconnected()), this, SLOT(on_disconnetedFromServer()));
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

    connect(login, SIGNAL(tryLogin(QString, QString)), this, SLOT(tryLogin(QString, QString)));

    login->show();
    if (login->exec()) {

    }
}

void
userInterface::recivedMessage(iiNPack::Header, QByteArray)
{

}

void
userInterface::tryLogin(QString login, QString pass)
{
    Q_EMIT setProgress(0, 1, "Logining", 0);
}

void
userInterface::on_logined()
{
    Q_EMIT setProgress(1, 1, "Login success", 0);
    ui->actionLogin->setEnabled(false);
    ui->actionLogout->setEnabled(true);
}

void
userInterface::on_login_failed()
{
    Q_EMIT setProgress(1, 1, "Login failed", 0);
    ui->actionLogin->setEnabled(true);
    ui->actionLogout->setEnabled(false);
}

void
userInterface::on_logouted()
{
    ui->actionLogin->setEnabled(true);
    ui->actionLogout->setEnabled(false);
}

/* void */
/* userInterface::on_actionLoginTriggered() */
/* { */
/*     /1* if (QSslSocket::supportsSsl() && _forseUseSsl) { *1/ */
/*     /1*     _service.connectToHostEncrypted(_serverAddress.toString(), _serverPort); *1/ */
/*     /1* } else { *1/ */
/*     /1*     _service.connectToHost(_serverAddress, _serverPort); *1/ */
/*     /1* } *1/ */
/* } */

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
