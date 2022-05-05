/********************************************************************************
** Form generated from reading UI file 'Accidents.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCIDENTS_H
#define UI_ACCIDENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Accidents
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Accidents)
    {
        if (Accidents->objectName().isEmpty())
            Accidents->setObjectName(QString::fromUtf8("Accidents"));
        Accidents->resize(521, 368);
        gridLayout = new QGridLayout(Accidents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(Accidents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1, Qt::AlignRight);

        tableWidget = new QTableWidget(Accidents);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);


        retranslateUi(Accidents);

        QMetaObject::connectSlotsByName(Accidents);
    } // setupUi

    void retranslateUi(QWidget *Accidents)
    {
        Accidents->setWindowTitle(QCoreApplication::translate("Accidents", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Accidents", "Register new", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Accidents", "name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Accidents", "date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Accidents: public Ui_Accidents {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCIDENTS_H
