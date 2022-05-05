/********************************************************************************
** Form generated from reading UI file 'RoleManagment.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROLEMANAGMENT_H
#define UI_ROLEMANAGMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoleManagment
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QListWidget *objectsList;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *name;
    QLabel *label_3;
    QPushButton *update;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;

    void setupUi(QWidget *RoleManagment)
    {
        if (RoleManagment->objectName().isEmpty())
            RoleManagment->setObjectName(QString::fromUtf8("RoleManagment"));
        RoleManagment->resize(561, 352);
        gridLayout = new QGridLayout(RoleManagment);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(RoleManagment);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        objectsList = new QListWidget(frame_2);
        objectsList->setObjectName(QString::fromUtf8("objectsList"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(objectsList->sizePolicy().hasHeightForWidth());
        objectsList->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(objectsList, 0, 0, 2, 1);

        frame = new QFrame(frame_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
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

        formLayout->setWidget(4, QFormLayout::SpanningRole, update);

        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        doubleSpinBox = new QDoubleSpinBox(frame);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox);

        doubleSpinBox_2 = new QDoubleSpinBox(frame);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, doubleSpinBox_2);


        gridLayout_2->addWidget(frame, 0, 2, 1, 1, Qt::AlignTop);


        gridLayout->addWidget(frame_2, 0, 0, 1, 1);


        retranslateUi(RoleManagment);

        QMetaObject::connectSlotsByName(RoleManagment);
    } // setupUi

    void retranslateUi(QWidget *RoleManagment)
    {
        RoleManagment->setWindowTitle(QCoreApplication::translate("RoleManagment", "Form", nullptr));
        label->setText(QCoreApplication::translate("RoleManagment", "Name", nullptr));
        name->setText(QCoreApplication::translate("RoleManagment", "-", nullptr));
        label_3->setText(QCoreApplication::translate("RoleManagment", "Avalible commands", nullptr));
        update->setText(QCoreApplication::translate("RoleManagment", "update", nullptr));
        label_2->setText(QCoreApplication::translate("RoleManagment", "Pay multipler", nullptr));
        label_4->setText(QCoreApplication::translate("RoleManagment", "Pay period", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoleManagment: public Ui_RoleManagment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROLEMANAGMENT_H
