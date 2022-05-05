/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QLabel *logo;
    QLabel *label_5;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *icon_password;
    QLineEdit *password;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *rememberLogin;
    QCheckBox *rememberPassword;
    QGridLayout *gridLayout_3;
    QLineEdit *port;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *host;
    QFrame *line_3;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *encryptionType;
    QFrame *line_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *icon_user;
    QLineEdit *login;
    QFrame *line;
    QPushButton *submit;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(477, 463);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Open Sans")});
        Login->setFont(font);
        Login->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("JetBrains Mono NL")});
        font1.setBold(false);
        font1.setItalic(false);
        label->setFont(font1);

        gridLayout->addWidget(label, 2, 1, 1, 1, Qt::AlignHCenter);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 3, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 3, 1);

        frame_2 = new QFrame(Login);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Monaco")});
        frame_2->setFont(font2);
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        logo = new QLabel(frame_2);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setMinimumSize(QSize(128, 128));
        logo->setMaximumSize(QSize(128, 128));
        logo->setFont(font2);

        verticalLayout->addWidget(logo, 0, Qt::AlignHCenter);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Monaco")});
        font3.setPointSize(18);
        label_5->setFont(font3);

        verticalLayout->addWidget(label_5, 0, Qt::AlignHCenter);


        gridLayout->addWidget(frame_2, 0, 1, 1, 1);

        frame = new QFrame(Login);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(241, 161));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Monaco")});
        font4.setPointSize(18);
        font4.setBold(true);
        frame->setFont(font4);
        frame->setStyleSheet(QString::fromUtf8("QGroupBox::title {}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(4);
        line_4 = new QFrame(frame);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_4, 1, 0, 1, 2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        icon_password = new QLabel(frame);
        icon_password->setObjectName(QString::fromUtf8("icon_password"));
        icon_password->setMinimumSize(QSize(24, 24));
        icon_password->setMaximumSize(QSize(24, 24));
        icon_password->setFont(font2);

        horizontalLayout_2->addWidget(icon_password, 0, Qt::AlignRight);

        password = new QLineEdit(frame);
        password->setObjectName(QString::fromUtf8("password"));

        horizontalLayout_2->addWidget(password);


        verticalLayout_3->addLayout(horizontalLayout_2);

        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);


        gridLayout_2->addLayout(verticalLayout_3, 5, 0, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        rememberLogin = new QCheckBox(frame);
        rememberLogin->setObjectName(QString::fromUtf8("rememberLogin"));

        verticalLayout_2->addWidget(rememberLogin);

        rememberPassword = new QCheckBox(frame);
        rememberPassword->setObjectName(QString::fromUtf8("rememberPassword"));

        verticalLayout_2->addWidget(rememberPassword);


        gridLayout_2->addLayout(verticalLayout_2, 7, 0, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        port = new QLineEdit(frame);
        port->setObjectName(QString::fromUtf8("port"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(port->sizePolicy().hasHeightForWidth());
        port->setSizePolicy(sizePolicy2);
        port->setMaximumSize(QSize(60, 16777215));

        gridLayout_3->addWidget(port, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        host = new QLineEdit(frame);
        host->setObjectName(QString::fromUtf8("host"));

        gridLayout_3->addWidget(host, 0, 0, 1, 1);

        line_3 = new QFrame(frame);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_3, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        encryptionType = new QComboBox(frame);
        encryptionType->setObjectName(QString::fromUtf8("encryptionType"));

        gridLayout_3->addWidget(encryptionType, 0, 4, 1, 1);

        line_5 = new QFrame(frame);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_5, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 0, 0, 1, 2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        icon_user = new QLabel(frame);
        icon_user->setObjectName(QString::fromUtf8("icon_user"));
        icon_user->setMinimumSize(QSize(24, 24));
        icon_user->setMaximumSize(QSize(24, 24));
        icon_user->setFont(font2);

        horizontalLayout->addWidget(icon_user, 0, Qt::AlignRight);

        login = new QLineEdit(frame);
        login->setObjectName(QString::fromUtf8("login"));

        horizontalLayout->addWidget(login);


        verticalLayout_4->addLayout(horizontalLayout);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);


        gridLayout_2->addLayout(verticalLayout_4, 2, 0, 1, 2);

        submit = new QPushButton(frame);
        submit->setObjectName(QString::fromUtf8("submit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(submit->sizePolicy().hasHeightForWidth());
        submit->setSizePolicy(sizePolicy3);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Open Sans")});
        font5.setPointSize(14);
        submit->setFont(font5);

        gridLayout_2->addWidget(submit, 8, 0, 1, 2);


        gridLayout->addWidget(frame, 1, 1, 1, 1);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        label->setText(QCoreApplication::translate("Login", "Call admin", nullptr));
        logo->setText(QCoreApplication::translate("Login", "<html><head/><body><p align=\"center\">ICON</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Login", "Log in", nullptr));
        icon_password->setText(QCoreApplication::translate("Login", "icn", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("Login", "Password", nullptr));
        rememberLogin->setText(QCoreApplication::translate("Login", "Remember login", nullptr));
        rememberPassword->setText(QCoreApplication::translate("Login", "Remeber password", nullptr));
        port->setPlaceholderText(QCoreApplication::translate("Login", "Port", nullptr));
        host->setPlaceholderText(QCoreApplication::translate("Login", "Host", nullptr));
        icon_user->setText(QCoreApplication::translate("Login", "icn", nullptr));
        login->setPlaceholderText(QCoreApplication::translate("Login", "Login", nullptr));
        submit->setText(QCoreApplication::translate("Login", "SIGN IN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
