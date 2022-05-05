/********************************************************************************
** Form generated from reading UI file 'AdminMain.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMAIN_H
#define UI_ADMINMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminMain
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label;

    void setupUi(QWidget *AdminMain)
    {
        if (AdminMain->objectName().isEmpty())
            AdminMain->setObjectName(QString::fromUtf8("AdminMain"));
        AdminMain->resize(588, 382);
        gridLayout = new QGridLayout(AdminMain);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(AdminMain);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1, Qt::AlignTop);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(AdminMain);

        QMetaObject::connectSlotsByName(AdminMain);
    } // setupUi

    void retranslateUi(QWidget *AdminMain)
    {
        AdminMain->setWindowTitle(QCoreApplication::translate("AdminMain", "Form", nullptr));
        label->setText(QCoreApplication::translate("AdminMain", "Admin ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminMain: public Ui_AdminMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMAIN_H
