/********************************************************************************
** Form generated from reading UI file 'Profile.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_H
#define UI_PROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Profile
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QFrame *frame_3;
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLabel *roleValue;
    QLabel *waponLabel;
    QLabel *waponValue;
    QLabel *label_8;
    QLabel *loginValue;
    QFrame *line;
    QLabel *label_10;
    QPushButton *editPasswordBtn;
    QLabel *label_3;
    QDateEdit *entryDate;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *personaImage;
    QLabel *personaName;

    void setupUi(QWidget *Profile)
    {
        if (Profile->objectName().isEmpty())
            Profile->setObjectName(QString::fromUtf8("Profile"));
        Profile->resize(672, 444);
        QFont font;
        font.setFamilies({QString::fromUtf8("JetBrains Mono")});
        Profile->setFont(font);
        gridLayout = new QGridLayout(Profile);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(Profile);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frame = new QFrame(frame_3);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        roleValue = new QLabel(frame);
        roleValue->setObjectName(QString::fromUtf8("roleValue"));

        formLayout->setWidget(2, QFormLayout::FieldRole, roleValue);

        waponLabel = new QLabel(frame);
        waponLabel->setObjectName(QString::fromUtf8("waponLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, waponLabel);

        waponValue = new QLabel(frame);
        waponValue->setObjectName(QString::fromUtf8("waponValue"));

        formLayout->setWidget(3, QFormLayout::FieldRole, waponValue);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_8);

        loginValue = new QLabel(frame);
        loginValue->setObjectName(QString::fromUtf8("loginValue"));

        formLayout->setWidget(5, QFormLayout::FieldRole, loginValue);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(4, QFormLayout::SpanningRole, line);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_10);

        editPasswordBtn = new QPushButton(frame);
        editPasswordBtn->setObjectName(QString::fromUtf8("editPasswordBtn"));
        editPasswordBtn->setEnabled(false);

        formLayout->setWidget(6, QFormLayout::FieldRole, editPasswordBtn);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        entryDate = new QDateEdit(frame);
        entryDate->setObjectName(QString::fromUtf8("entryDate"));
        entryDate->setReadOnly(true);
        entryDate->setButtonSymbols(QAbstractSpinBox::NoButtons);
        entryDate->setKeyboardTracking(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, entryDate);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("JetBrains Mono")});
        font1.setPointSize(11);
        label->setFont(font1);

        formLayout->setWidget(0, QFormLayout::SpanningRole, label);


        gridLayout_3->addWidget(frame, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 1, 0, 1, 1);


        gridLayout_2->addWidget(frame_3, 0, 1, 3, 1);

        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        personaImage = new QLabel(frame_4);
        personaImage->setObjectName(QString::fromUtf8("personaImage"));
        sizePolicy.setHeightForWidth(personaImage->sizePolicy().hasHeightForWidth());
        personaImage->setSizePolicy(sizePolicy);
        personaImage->setMinimumSize(QSize(218, 218));
        personaImage->setFrameShape(QFrame::NoFrame);

        verticalLayout_2->addWidget(personaImage);

        personaName = new QLabel(frame_4);
        personaName->setObjectName(QString::fromUtf8("personaName"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Monaco")});
        font2.setPointSize(10);
        personaName->setFont(font2);

        verticalLayout_2->addWidget(personaName);


        gridLayout_2->addWidget(frame_4, 0, 0, 2, 1);


        gridLayout->addWidget(frame_2, 1, 1, 1, 1);


        retranslateUi(Profile);

        QMetaObject::connectSlotsByName(Profile);
    } // setupUi

    void retranslateUi(QWidget *Profile)
    {
        Profile->setWindowTitle(QCoreApplication::translate("Profile", "Form", nullptr));
        label_4->setText(QCoreApplication::translate("Profile", "Role", nullptr));
        roleValue->setText(QCoreApplication::translate("Profile", "-", nullptr));
        waponLabel->setText(QCoreApplication::translate("Profile", "Wapon", nullptr));
        waponValue->setText(QCoreApplication::translate("Profile", "None", nullptr));
        label_8->setText(QCoreApplication::translate("Profile", "Login", nullptr));
        loginValue->setText(QCoreApplication::translate("Profile", "-", nullptr));
        label_10->setText(QCoreApplication::translate("Profile", "Password", nullptr));
        editPasswordBtn->setText(QCoreApplication::translate("Profile", "Edit", nullptr));
        label_3->setText(QCoreApplication::translate("Profile", "Entry date", nullptr));
        label->setText(QCoreApplication::translate("Profile", "Account info", nullptr));
        personaImage->setText(QString());
        personaName->setText(QCoreApplication::translate("Profile", "Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Profile: public Ui_Profile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_H
