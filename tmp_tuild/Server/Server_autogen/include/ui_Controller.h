/********************************************************************************
** Form generated from reading UI file 'Controller.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLER_H
#define UI_CONTROLLER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Controller
{
public:
    QAction *actionVisit_shelly_wiki;
    QAction *actionMinimize;
    QAction *actionQuit;
    QAction *actionProperties;
    QAction *actionToggle_server;
    QAction *actionDark;
    QAction *actionLight;
    QAction *actionEnglish;
    QAction *actionRussian;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuServices;
    QMenu *menuHelp;
    QMenu *menuTheme;
    QMenu *menuLanguage;
    QStatusBar *statusbar;
    QDockWidget *info_dock;
    QWidget *loggingDock;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QComboBox *logLevel_cb;
    QTextEdit *loggingOutput;
    QPushButton *clearLogButton;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Controller)
    {
        if (Controller->objectName().isEmpty())
            Controller->setObjectName(QString::fromUtf8("Controller"));
        Controller->setWindowModality(Qt::WindowModal);
        Controller->resize(1173, 692);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Controller->sizePolicy().hasHeightForWidth());
        Controller->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("JetBrains Mono")});
        Controller->setFont(font);
        Controller->setStyleSheet(QString::fromUtf8(""));
        Controller->setToolButtonStyle(Qt::ToolButtonTextOnly);
        Controller->setAnimated(true);
        Controller->setDocumentMode(false);
        Controller->setTabShape(QTabWidget::Triangular);
        Controller->setDockNestingEnabled(false);
        Controller->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::GroupedDragging);
        actionVisit_shelly_wiki = new QAction(Controller);
        actionVisit_shelly_wiki->setObjectName(QString::fromUtf8("actionVisit_shelly_wiki"));
        actionMinimize = new QAction(Controller);
        actionMinimize->setObjectName(QString::fromUtf8("actionMinimize"));
        actionQuit = new QAction(Controller);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionProperties = new QAction(Controller);
        actionProperties->setObjectName(QString::fromUtf8("actionProperties"));
        actionToggle_server = new QAction(Controller);
        actionToggle_server->setObjectName(QString::fromUtf8("actionToggle_server"));
        actionDark = new QAction(Controller);
        actionDark->setObjectName(QString::fromUtf8("actionDark"));
        actionLight = new QAction(Controller);
        actionLight->setObjectName(QString::fromUtf8("actionLight"));
        actionEnglish = new QAction(Controller);
        actionEnglish->setObjectName(QString::fromUtf8("actionEnglish"));
        actionRussian = new QAction(Controller);
        actionRussian->setObjectName(QString::fromUtf8("actionRussian"));
        centralwidget = new QWidget(Controller);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Controller->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Controller);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1173, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Monaco")});
        menubar->setFont(font1);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuServices = new QMenu(menubar);
        menuServices->setObjectName(QString::fromUtf8("menuServices"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuTheme = new QMenu(menubar);
        menuTheme->setObjectName(QString::fromUtf8("menuTheme"));
        menuLanguage = new QMenu(menubar);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        Controller->setMenuBar(menubar);
        statusbar = new QStatusBar(Controller);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(statusbar->sizePolicy().hasHeightForWidth());
        statusbar->setSizePolicy(sizePolicy2);
        statusbar->setMinimumSize(QSize(0, 22));
        statusbar->setMaximumSize(QSize(16777215, 22));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Source Code Pro")});
        font2.setPointSize(7);
        statusbar->setFont(font2);
        statusbar->setMouseTracking(false);
        statusbar->setTabletTracking(false);
        statusbar->setFocusPolicy(Qt::ClickFocus);
        statusbar->setContextMenuPolicy(Qt::NoContextMenu);
        statusbar->setAcceptDrops(false);
        statusbar->setLayoutDirection(Qt::LeftToRight);
        statusbar->setAutoFillBackground(false);
        statusbar->setStyleSheet(QString::fromUtf8("QStatusBar#statusbar {\n"
"border-top: 2px solid #bbb;\n"
"border-style: groove;\n"
"}"));
        statusbar->setInputMethodHints(Qt::ImhNone);
        statusbar->setSizeGripEnabled(true);
        Controller->setStatusBar(statusbar);
        info_dock = new QDockWidget(Controller);
        info_dock->setObjectName(QString::fromUtf8("info_dock"));
        info_dock->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(info_dock->sizePolicy().hasHeightForWidth());
        info_dock->setSizePolicy(sizePolicy3);
        info_dock->setFloating(false);
        info_dock->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        info_dock->setAllowedAreas(Qt::AllDockWidgetAreas);
        loggingDock = new QWidget();
        loggingDock->setObjectName(QString::fromUtf8("loggingDock"));
        gridLayout_2 = new QGridLayout(loggingDock);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(loggingDock);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(label, 0, 1, 1, 1);

        logLevel_cb = new QComboBox(frame);
        logLevel_cb->addItem(QString());
        logLevel_cb->addItem(QString());
        logLevel_cb->addItem(QString());
        logLevel_cb->addItem(QString());
        logLevel_cb->addItem(QString());
        logLevel_cb->addItem(QString());
        logLevel_cb->setObjectName(QString::fromUtf8("logLevel_cb"));
        sizePolicy4.setHeightForWidth(logLevel_cb->sizePolicy().hasHeightForWidth());
        logLevel_cb->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(logLevel_cb, 0, 2, 1, 1);

        loggingOutput = new QTextEdit(frame);
        loggingOutput->setObjectName(QString::fromUtf8("loggingOutput"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(loggingOutput->sizePolicy().hasHeightForWidth());
        loggingOutput->setSizePolicy(sizePolicy5);
        loggingOutput->setMinimumSize(QSize(0, 20));
        loggingOutput->setMaximumSize(QSize(16777215, 16777215));
        loggingOutput->setFrameShape(QFrame::Box);
        loggingOutput->setReadOnly(true);
        loggingOutput->setCursorWidth(0);

        gridLayout_3->addWidget(loggingOutput, 1, 0, 1, 4);

        clearLogButton = new QPushButton(frame);
        clearLogButton->setObjectName(QString::fromUtf8("clearLogButton"));
        sizePolicy4.setHeightForWidth(clearLogButton->sizePolicy().hasHeightForWidth());
        clearLogButton->setSizePolicy(sizePolicy4);
        clearLogButton->setLayoutDirection(Qt::LeftToRight);

        gridLayout_3->addWidget(clearLogButton, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        info_dock->setWidget(loggingDock);
        Controller->addDockWidget(Qt::BottomDockWidgetArea, info_dock);
        toolBar = new QToolBar(Controller);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy6);
        toolBar->setFont(font1);
        Controller->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuServices->menuAction());
        menubar->addAction(menuTheme->menuAction());
        menubar->addAction(menuLanguage->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionMinimize);
        menuFile->addAction(actionQuit);
        menuServices->addAction(actionProperties);
        menuHelp->addAction(actionVisit_shelly_wiki);
        menuTheme->addAction(actionDark);
        menuTheme->addAction(actionLight);
        menuLanguage->addAction(actionEnglish);
        menuLanguage->addAction(actionRussian);
        toolBar->addAction(actionToggle_server);
        toolBar->addSeparator();

        retranslateUi(Controller);

        QMetaObject::connectSlotsByName(Controller);
    } // setupUi

    void retranslateUi(QMainWindow *Controller)
    {
        Controller->setWindowTitle(QCoreApplication::translate("Controller", "Controller", nullptr));
        actionVisit_shelly_wiki->setText(QCoreApplication::translate("Controller", "Visit shelly wiki", nullptr));
        actionMinimize->setText(QCoreApplication::translate("Controller", "Minimize", nullptr));
        actionQuit->setText(QCoreApplication::translate("Controller", "Quit", nullptr));
        actionProperties->setText(QCoreApplication::translate("Controller", "Settings", nullptr));
        actionToggle_server->setText(QCoreApplication::translate("Controller", "Trigger", nullptr));
#if QT_CONFIG(tooltip)
        actionToggle_server->setToolTip(QCoreApplication::translate("Controller", "Toggle server state", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDark->setText(QCoreApplication::translate("Controller", "Dark", nullptr));
        actionLight->setText(QCoreApplication::translate("Controller", "Light", nullptr));
        actionEnglish->setText(QCoreApplication::translate("Controller", "English", nullptr));
        actionRussian->setText(QCoreApplication::translate("Controller", "Russian", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Controller", "File", nullptr));
        menuServices->setTitle(QCoreApplication::translate("Controller", "Tools", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("Controller", "Help", nullptr));
        menuTheme->setTitle(QCoreApplication::translate("Controller", "Theme", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("Controller", "Language", nullptr));
        info_dock->setWindowTitle(QCoreApplication::translate("Controller", "Log messages", nullptr));
        label->setText(QCoreApplication::translate("Controller", "Log level:", nullptr));
        logLevel_cb->setItemText(0, QCoreApplication::translate("Controller", "Trace", nullptr));
        logLevel_cb->setItemText(1, QCoreApplication::translate("Controller", "Debug", nullptr));
        logLevel_cb->setItemText(2, QCoreApplication::translate("Controller", "Info", nullptr));
        logLevel_cb->setItemText(3, QCoreApplication::translate("Controller", "Warning", nullptr));
        logLevel_cb->setItemText(4, QCoreApplication::translate("Controller", "Error", nullptr));
        logLevel_cb->setItemText(5, QCoreApplication::translate("Controller", "Fatal", nullptr));

        loggingOutput->setDocumentTitle(QCoreApplication::translate("Controller", "Logger", nullptr));
        clearLogButton->setText(QCoreApplication::translate("Controller", "Clear", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("Controller", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Controller: public Ui_Controller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLER_H
