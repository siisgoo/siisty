/********************************************************************************
** Form generated from reading UI file 'Users.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERS_H
#define UI_USERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Users
{
public:

    void setupUi(QWidget *Users)
    {
        if (Users->objectName().isEmpty())
            Users->setObjectName(QString::fromUtf8("Users"));
        Users->resize(400, 300);

        retranslateUi(Users);

        QMetaObject::connectSlotsByName(Users);
    } // setupUi

    void retranslateUi(QWidget *Users)
    {
        Users->setWindowTitle(QCoreApplication::translate("Users", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Users: public Ui_Users {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERS_H
