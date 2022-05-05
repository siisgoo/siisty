/********************************************************************************
** Form generated from reading UI file 'PersonalAccounting.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONALACCOUNTING_H
#define UI_PERSONALACCOUNTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonalAccounting
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame_3;
    QGridLayout *gridLayout_3;
    QLabel *overallPayments;
    QLabel *label_11;
    QTableWidget *paymentTable;

    void setupUi(QWidget *PersonalAccounting)
    {
        if (PersonalAccounting->objectName().isEmpty())
            PersonalAccounting->setObjectName(QString::fromUtf8("PersonalAccounting"));
        PersonalAccounting->resize(400, 300);
        horizontalLayout = new QHBoxLayout(PersonalAccounting);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame_3 = new QFrame(PersonalAccounting);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_3);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        overallPayments = new QLabel(frame_3);
        overallPayments->setObjectName(QString::fromUtf8("overallPayments"));

        gridLayout_3->addWidget(overallPayments, 1, 1, 1, 1);

        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_11, 1, 0, 1, 1);

        paymentTable = new QTableWidget(frame_3);
        if (paymentTable->columnCount() < 3)
            paymentTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        paymentTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        paymentTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        paymentTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        paymentTable->setObjectName(QString::fromUtf8("paymentTable"));
        paymentTable->horizontalHeader()->setDefaultSectionSize(126);

        gridLayout_3->addWidget(paymentTable, 0, 0, 1, 2);


        horizontalLayout->addWidget(frame_3);


        retranslateUi(PersonalAccounting);

        QMetaObject::connectSlotsByName(PersonalAccounting);
    } // setupUi

    void retranslateUi(QWidget *PersonalAccounting)
    {
        PersonalAccounting->setWindowTitle(QCoreApplication::translate("PersonalAccounting", "Form", nullptr));
        overallPayments->setText(QCoreApplication::translate("PersonalAccounting", "0", nullptr));
        label_11->setText(QCoreApplication::translate("PersonalAccounting", "Over all payments:  ", nullptr));
        QTableWidgetItem *___qtablewidgetitem = paymentTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("PersonalAccounting", "Pay amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = paymentTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("PersonalAccounting", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = paymentTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("PersonalAccounting", "Objective", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonalAccounting: public Ui_PersonalAccounting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONALACCOUNTING_H
