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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Controller
{
public:
    QAction *actionLogin;
    QAction *actionLogout;
    QAction *actionQuit;
    QAction *actionsiisty_wiki;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Controller)
    {
        if (Controller->objectName().isEmpty())
            Controller->setObjectName(QString::fromUtf8("Controller"));
        Controller->resize(800, 600);
        Controller->setStyleSheet(QString::fromUtf8("QStatusBar#statusbar {\n"
"border-top: 2px solid #bbb;\n"
"border-style: groove;\n"
"}"));
        actionLogin = new QAction(Controller);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionLogout = new QAction(Controller);
        actionLogout->setObjectName(QString::fromUtf8("actionLogout"));
        actionLogout->setEnabled(false);
        actionQuit = new QAction(Controller);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionsiisty_wiki = new QAction(Controller);
        actionsiisty_wiki->setObjectName(QString::fromUtf8("actionsiisty_wiki"));
        centralwidget = new QWidget(Controller);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Controller->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Controller);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        Controller->setMenuBar(menubar);
        statusbar = new QStatusBar(Controller);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Controller->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLogout);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionsiisty_wiki);

        retranslateUi(Controller);

        QMetaObject::connectSlotsByName(Controller);
    } // setupUi

    void retranslateUi(QMainWindow *Controller)
    {
        Controller->setWindowTitle(QCoreApplication::translate("Controller", "MainWindow", nullptr));
        actionLogin->setText(QCoreApplication::translate("Controller", "Login", nullptr));
        actionLogout->setText(QCoreApplication::translate("Controller", "Logout", nullptr));
        actionQuit->setText(QCoreApplication::translate("Controller", "Quit", nullptr));
        actionsiisty_wiki->setText(QCoreApplication::translate("Controller", "siisty wiki", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Controller", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("Controller", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Controller: public Ui_Controller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLER_H
