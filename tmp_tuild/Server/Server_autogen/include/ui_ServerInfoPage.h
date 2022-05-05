/********************************************************************************
** Form generated from reading UI file 'ServerInfoPage.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERINFOPAGE_H
#define UI_SERVERINFOPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerInfoPage
{
public:
    QFormLayout *formLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_server_status;
    QLabel *label_3;
    QLabel *label_online_time;
    QLabel *label_4;
    QLineEdit *server_port_edit;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_3;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label_12;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *ServerInfoPage)
    {
        if (ServerInfoPage->objectName().isEmpty())
            ServerInfoPage->setObjectName(QString::fromUtf8("ServerInfoPage"));
        ServerInfoPage->resize(475, 433);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ServerInfoPage->sizePolicy().hasHeightForWidth());
        ServerInfoPage->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Anonymous Pro")});
        font.setBold(true);
        ServerInfoPage->setFont(font);
        ServerInfoPage->setStyleSheet(QString::fromUtf8(""));
        formLayout_2 = new QFormLayout(ServerInfoPage);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setHorizontalSpacing(0);
        formLayout_2->setVerticalSpacing(0);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(ServerInfoPage);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(0, 0, 0, 6);
        scrollArea = new QScrollArea(frame);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setFrameShape(QFrame::StyledPanel);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setLineWidth(1);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 473, 391));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        formLayout = new QFormLayout(groupBox_3);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_server_status = new QLabel(groupBox_3);
        label_server_status->setObjectName(QString::fromUtf8("label_server_status"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_server_status);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_online_time = new QLabel(groupBox_3);
        label_online_time->setObjectName(QString::fromUtf8("label_online_time"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_online_time);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        server_port_edit = new QLineEdit(groupBox_3);
        server_port_edit->setObjectName(QString::fromUtf8("server_port_edit"));
        server_port_edit->setMaximumSize(QSize(200, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, server_port_edit);


        verticalLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        formLayout_3 = new QFormLayout(groupBox_2);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_10);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_7);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_9);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, label_11);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, label_8);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, label_12);


        verticalLayout->addWidget(groupBox_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 3);

        buttonBox = new QDialogButtonBox(frame);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel);
        buttonBox->setCenterButtons(false);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        formLayout_2->setWidget(0, QFormLayout::FieldRole, frame);


        retranslateUi(ServerInfoPage);

        QMetaObject::connectSlotsByName(ServerInfoPage);
    } // setupUi

    void retranslateUi(QWidget *ServerInfoPage)
    {
        ServerInfoPage->setWindowTitle(QCoreApplication::translate("ServerInfoPage", "Form", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("ServerInfoPage", "Service", nullptr));
        label->setText(QCoreApplication::translate("ServerInfoPage", "Status:", nullptr));
        label_server_status->setText(QCoreApplication::translate("ServerInfoPage", "offline", nullptr));
        label_3->setText(QCoreApplication::translate("ServerInfoPage", "Online time:", nullptr));
        label_online_time->setText(QCoreApplication::translate("ServerInfoPage", "0s", nullptr));
        label_4->setText(QCoreApplication::translate("ServerInfoPage", "Port:", nullptr));
        server_port_edit->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("ServerInfoPage", "Proxy", nullptr));
        label_10->setText(QCoreApplication::translate("ServerInfoPage", "Type:", nullptr));
        label_7->setText(QCoreApplication::translate("ServerInfoPage", "Host:", nullptr));
        label_9->setText(QCoreApplication::translate("ServerInfoPage", "Port:", nullptr));
        label_11->setText(QCoreApplication::translate("ServerInfoPage", "none", nullptr));
        label_8->setText(QCoreApplication::translate("ServerInfoPage", "none", nullptr));
        label_12->setText(QCoreApplication::translate("ServerInfoPage", "none", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerInfoPage: public Ui_ServerInfoPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERINFOPAGE_H
