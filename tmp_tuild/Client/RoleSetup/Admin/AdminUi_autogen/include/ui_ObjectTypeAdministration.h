/********************************************************************************
** Form generated from reading UI file 'ObjectTypeAdministration.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECTTYPEADMINISTRATION_H
#define UI_OBJECTTYPEADMINISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ObjectTypeAdministration
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
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *registerNew;
    QListWidget *objectsList;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ObjectTypeAdministration)
    {
        if (ObjectTypeAdministration->objectName().isEmpty())
            ObjectTypeAdministration->setObjectName(QString::fromUtf8("ObjectTypeAdministration"));
        ObjectTypeAdministration->resize(481, 344);
        gridLayout = new QGridLayout(ObjectTypeAdministration);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(ObjectTypeAdministration);
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

        formLayout->setWidget(2, QFormLayout::SpanningRole, update);

        doubleSpinBox = new QDoubleSpinBox(frame);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, doubleSpinBox);


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


        gridLayout->addWidget(frame_2, 0, 1, 1, 1);


        retranslateUi(ObjectTypeAdministration);

        QMetaObject::connectSlotsByName(ObjectTypeAdministration);
    } // setupUi

    void retranslateUi(QWidget *ObjectTypeAdministration)
    {
        ObjectTypeAdministration->setWindowTitle(QCoreApplication::translate("ObjectTypeAdministration", "Form", nullptr));
        label->setText(QCoreApplication::translate("ObjectTypeAdministration", "Name", nullptr));
        name->setText(QCoreApplication::translate("ObjectTypeAdministration", "-", nullptr));
        label_3->setText(QCoreApplication::translate("ObjectTypeAdministration", "Month Price", nullptr));
        update->setText(QCoreApplication::translate("ObjectTypeAdministration", "update", nullptr));
        registerNew->setText(QCoreApplication::translate("ObjectTypeAdministration", "Register new", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ObjectTypeAdministration: public Ui_ObjectTypeAdministration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTTYPEADMINISTRATION_H
