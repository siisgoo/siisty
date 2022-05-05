/********************************************************************************
** Form generated from reading UI file 'DutySchedule.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUTYSCHEDULE_H
#define UI_DUTYSCHEDULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DutySchedule
{
public:

    void setupUi(QWidget *DutySchedule)
    {
        if (DutySchedule->objectName().isEmpty())
            DutySchedule->setObjectName(QString::fromUtf8("DutySchedule"));
        DutySchedule->resize(400, 300);

        retranslateUi(DutySchedule);

        QMetaObject::connectSlotsByName(DutySchedule);
    } // setupUi

    void retranslateUi(QWidget *DutySchedule)
    {
        DutySchedule->setWindowTitle(QCoreApplication::translate("DutySchedule", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DutySchedule: public Ui_DutySchedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUTYSCHEDULE_H
