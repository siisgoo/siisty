/********************************************************************************
** Form generated from reading UI file 'DebugConsole.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGCONSOLE_H
#define UI_DEBUGCONSOLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_DebugConsole
{
public:

    void setupUi(QDialog *DebugConsole)
    {
        if (DebugConsole->objectName().isEmpty())
            DebugConsole->setObjectName(QString::fromUtf8("DebugConsole"));
        DebugConsole->resize(400, 300);

        retranslateUi(DebugConsole);

        QMetaObject::connectSlotsByName(DebugConsole);
    } // setupUi

    void retranslateUi(QDialog *DebugConsole)
    {
        DebugConsole->setWindowTitle(QCoreApplication::translate("DebugConsole", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DebugConsole: public Ui_DebugConsole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGCONSOLE_H
