/********************************************************************************
** Form generated from reading UI file 'RegisterUser.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERUSER_H
#define UI_REGISTERUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterUser
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QPushButton *update_wapons;
    QDateEdit *entryDate_edit;
    QLineEdit *email_edit;
    QLineEdit *password_edit;
    QLabel *label_7;
    QLineEdit *image_path_edit;
    QLabel *label;
    QLabel *label_4;
    QComboBox *role_cb;
    QLineEdit *login_edit;
    QLabel *label_6;
    QLabel *label_9;
    QPushButton *openImageFile_btn;
    QDialogButtonBox *register_buttons;
    QLineEdit *name_edit;
    QComboBox *wapon_cb;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_5;
    QFrame *line;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_8;

    void setupUi(QWidget *RegisterUser)
    {
        if (RegisterUser->objectName().isEmpty())
            RegisterUser->setObjectName(QString::fromUtf8("RegisterUser"));
        RegisterUser->resize(555, 387);
        gridLayout = new QGridLayout(RegisterUser);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(RegisterUser);
        frame->setObjectName(QString::fromUtf8("frame"));
        QFont font;
        font.setFamilies({QString::fromUtf8("JetBrains Mono")});
        frame->setFont(font);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        update_wapons = new QPushButton(frame_2);
        update_wapons->setObjectName(QString::fromUtf8("update_wapons"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(update_wapons->sizePolicy().hasHeightForWidth());
        update_wapons->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(update_wapons, 4, 4, 1, 1);

        entryDate_edit = new QDateEdit(frame_2);
        entryDate_edit->setObjectName(QString::fromUtf8("entryDate_edit"));

        gridLayout_3->addWidget(entryDate_edit, 3, 3, 1, 2);

        email_edit = new QLineEdit(frame_2);
        email_edit->setObjectName(QString::fromUtf8("email_edit"));

        gridLayout_3->addWidget(email_edit, 6, 3, 1, 2);

        password_edit = new QLineEdit(frame_2);
        password_edit->setObjectName(QString::fromUtf8("password_edit"));
        password_edit->setAutoFillBackground(false);
        password_edit->setEchoMode(QLineEdit::Password);
        password_edit->setClearButtonEnabled(true);

        gridLayout_3->addWidget(password_edit, 2, 3, 1, 2);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(label_7, 7, 0, 1, 1);

        image_path_edit = new QLineEdit(frame_2);
        image_path_edit->setObjectName(QString::fromUtf8("image_path_edit"));

        gridLayout_3->addWidget(image_path_edit, 7, 3, 1, 1);

        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 4, 0, 1, 1);

        role_cb = new QComboBox(frame_2);
        role_cb->setObjectName(QString::fromUtf8("role_cb"));

        gridLayout_3->addWidget(role_cb, 5, 3, 1, 2);

        login_edit = new QLineEdit(frame_2);
        login_edit->setObjectName(QString::fromUtf8("login_edit"));

        gridLayout_3->addWidget(login_edit, 1, 3, 1, 2);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 6, 0, 1, 1);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        openImageFile_btn = new QPushButton(frame_2);
        openImageFile_btn->setObjectName(QString::fromUtf8("openImageFile_btn"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(openImageFile_btn->sizePolicy().hasHeightForWidth());
        openImageFile_btn->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(openImageFile_btn, 7, 4, 1, 1);

        register_buttons = new QDialogButtonBox(frame_2);
        register_buttons->setObjectName(QString::fromUtf8("register_buttons"));
        register_buttons->setStandardButtons(QDialogButtonBox::Discard|QDialogButtonBox::Save);

        gridLayout_3->addWidget(register_buttons, 9, 2, 1, 3);

        name_edit = new QLineEdit(frame_2);
        name_edit->setObjectName(QString::fromUtf8("name_edit"));

        gridLayout_3->addWidget(name_edit, 0, 3, 1, 2);

        wapon_cb = new QComboBox(frame_2);
        wapon_cb->setObjectName(QString::fromUtf8("wapon_cb"));
        wapon_cb->setFrame(true);
        wapon_cb->setModelColumn(0);

        gridLayout_3->addWidget(wapon_cb, 4, 3, 1, 1);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 3, 0, 1, 1);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 2, 0, 1, 1);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 5, 0, 1, 1);

        line = new QFrame(frame_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 8, 0, 1, 5);


        gridLayout_2->addWidget(frame_2, 1, 2, 3, 1, Qt::AlignTop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 4, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 3, 4, 1);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Monaco")});
        font1.setBold(false);
        font1.setItalic(false);
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("font: 16px;"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 0, 2, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(RegisterUser);

        QMetaObject::connectSlotsByName(RegisterUser);
    } // setupUi

    void retranslateUi(QWidget *RegisterUser)
    {
        RegisterUser->setWindowTitle(QCoreApplication::translate("RegisterUser", "Form", nullptr));
        update_wapons->setText(QCoreApplication::translate("RegisterUser", "Update", nullptr));
        email_edit->setInputMask(QString());
        email_edit->setText(QString());
        label_7->setText(QCoreApplication::translate("RegisterUser", "Image", nullptr));
        label->setText(QCoreApplication::translate("RegisterUser", "Login", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterUser", "Wapon", nullptr));
        label_6->setText(QCoreApplication::translate("RegisterUser", "Email", nullptr));
        label_9->setText(QCoreApplication::translate("RegisterUser", "Name", nullptr));
        openImageFile_btn->setText(QCoreApplication::translate("RegisterUser", "Open", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterUser", "Entry date", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterUser", "Password", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterUser", "Role", nullptr));
        label_8->setText(QCoreApplication::translate("RegisterUser", "Employee registration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterUser: public Ui_RegisterUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERUSER_H
