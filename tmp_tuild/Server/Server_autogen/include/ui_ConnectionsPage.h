/********************************************************************************
** Form generated from reading UI file 'ConnectionsPage.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONSPAGE_H
#define UI_CONNECTIONSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionsPage
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_connected_clients_count;
    QTableWidget *connected_clients;

    void setupUi(QWidget *ConnectionsPage)
    {
        if (ConnectionsPage->objectName().isEmpty())
            ConnectionsPage->setObjectName(QString::fromUtf8("ConnectionsPage"));
        ConnectionsPage->resize(541, 398);
        QFont font;
        font.setFamilies({QString::fromUtf8("Anonymous Pro")});
        ConnectionsPage->setFont(font);
        gridLayout_2 = new QGridLayout(ConnectionsPage);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(ConnectionsPage);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(0, 0));
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_connected_clients_count = new QLabel(frame);
        label_connected_clients_count->setObjectName(QString::fromUtf8("label_connected_clients_count"));

        gridLayout->addWidget(label_connected_clients_count, 2, 1, 1, 1);

        connected_clients = new QTableWidget(frame);
        if (connected_clients->columnCount() < 5)
            connected_clients->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        connected_clients->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        connected_clients->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        connected_clients->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        connected_clients->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        connected_clients->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        connected_clients->setObjectName(QString::fromUtf8("connected_clients"));
        connected_clients->horizontalHeader()->setVisible(true);
        connected_clients->horizontalHeader()->setCascadingSectionResizes(false);
        connected_clients->horizontalHeader()->setHighlightSections(true);
        connected_clients->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        connected_clients->horizontalHeader()->setStretchLastSection(true);
        connected_clients->verticalHeader()->setCascadingSectionResizes(true);

        gridLayout->addWidget(connected_clients, 4, 0, 1, 2);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(ConnectionsPage);

        QMetaObject::connectSlotsByName(ConnectionsPage);
    } // setupUi

    void retranslateUi(QWidget *ConnectionsPage)
    {
        ConnectionsPage->setWindowTitle(QCoreApplication::translate("ConnectionsPage", "Form", nullptr));
        label->setText(QCoreApplication::translate("ConnectionsPage", "Connections:", nullptr));
        label_connected_clients_count->setText(QCoreApplication::translate("ConnectionsPage", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem = connected_clients->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ConnectionsPage", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = connected_clients->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ConnectionsPage", "IP", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = connected_clients->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ConnectionsPage", "Port", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = connected_clients->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ConnectionsPage", "Authed", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = connected_clients->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ConnectionsPage", "Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectionsPage: public Ui_ConnectionsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONSPAGE_H
