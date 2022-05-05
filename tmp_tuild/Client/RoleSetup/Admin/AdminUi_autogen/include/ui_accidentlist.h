/********************************************************************************
** Form generated from reading UI file 'accidentlist.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCIDENTLIST_H
#define UI_ACCIDENTLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccidentList
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *name;
    QLabel *label_3;
    QPushButton *update;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton;
    QPushButton *registerNew;
    QListWidget *objectsList;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *AccidentList)
    {
        if (AccidentList->objectName().isEmpty())
            AccidentList->setObjectName(QString::fromUtf8("AccidentList"));
        AccidentList->resize(551, 349);
        gridLayout = new QGridLayout(AccidentList);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(AccidentList);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(frame_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(150, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        name = new QLabel(frame);
        name->setObjectName(QString::fromUtf8("name"));

        formLayout->setWidget(0, QFormLayout::FieldRole, name);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        update = new QPushButton(frame);
        update->setObjectName(QString::fromUtf8("update"));

        formLayout->setWidget(5, QFormLayout::SpanningRole, update);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_2);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_5);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(3, QFormLayout::FieldRole, label_7);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout->setWidget(4, QFormLayout::FieldRole, pushButton);


        gridLayout_2->addWidget(frame, 0, 2, 1, 1, Qt::AlignTop);

        registerNew = new QPushButton(frame_2);
        registerNew->setObjectName(QString::fromUtf8("registerNew"));

        gridLayout_2->addWidget(registerNew, 2, 2, 1, 1);

        objectsList = new QListWidget(frame_2);
        objectsList->setObjectName(QString::fromUtf8("objectsList"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(objectsList->sizePolicy().hasHeightForWidth());
        objectsList->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(objectsList, 0, 0, 3, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 2, 1, 1);


        gridLayout->addWidget(frame_2, 0, 0, 1, 1);


        retranslateUi(AccidentList);

        QMetaObject::connectSlotsByName(AccidentList);
    } // setupUi

    void retranslateUi(QWidget *AccidentList)
    {
        AccidentList->setWindowTitle(QCoreApplication::translate("AccidentList", "Form", nullptr));
        label->setText(QCoreApplication::translate("AccidentList", "Name", nullptr));
        name->setText(QCoreApplication::translate("AccidentList", "-", nullptr));
        label_3->setText(QCoreApplication::translate("AccidentList", "Contract", nullptr));
        update->setText(QCoreApplication::translate("AccidentList", "update", nullptr));
        label_2->setText(QCoreApplication::translate("AccidentList", "-", nullptr));
        label_4->setText(QCoreApplication::translate("AccidentList", "Used ammo", nullptr));
        label_5->setText(QCoreApplication::translate("AccidentList", "0", nullptr));
        label_6->setText(QCoreApplication::translate("AccidentList", "Damage price", nullptr));
        label_7->setText(QCoreApplication::translate("AccidentList", "0", nullptr));
        label_8->setText(QCoreApplication::translate("AccidentList", "Guilty employees", nullptr));
        pushButton->setText(QCoreApplication::translate("AccidentList", "Show", nullptr));
        registerNew->setText(QCoreApplication::translate("AccidentList", "Register new", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccidentList: public Ui_AccidentList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCIDENTLIST_H
