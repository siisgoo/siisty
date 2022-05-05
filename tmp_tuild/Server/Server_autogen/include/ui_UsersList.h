/********************************************************************************
** Form generated from reading UI file 'UsersList.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSLIST_H
#define UI_USERSLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsersList
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QTableWidget *users_table;
    QPushButton *update_users_Btn;
    QFrame *frame1;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *label_6;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_3;
    QLabel *label_10;
    QLabel *label_4;
    QLabel *label_11;
    QLabel *label_5;
    QLabel *label_12;

    void setupUi(QWidget *UsersList)
    {
        if (UsersList->objectName().isEmpty())
            UsersList->setObjectName(QString::fromUtf8("UsersList"));
        UsersList->resize(770, 565);
        QFont font;
        font.setFamilies({QString::fromUtf8("Anonymous Pro")});
        UsersList->setFont(font);
        gridLayout = new QGridLayout(UsersList);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(UsersList);
        frame->setObjectName(QString::fromUtf8("frame"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("JetBrains Mono")});
        frame->setFont(font1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        users_table = new QTableWidget(frame);
        if (users_table->columnCount() < 3)
            users_table->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        users_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        users_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        users_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        users_table->setObjectName(QString::fromUtf8("users_table"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(users_table->sizePolicy().hasHeightForWidth());
        users_table->setSizePolicy(sizePolicy);
        users_table->setFocusPolicy(Qt::ClickFocus);
        users_table->setContextMenuPolicy(Qt::ActionsContextMenu);
        users_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        users_table->setDragEnabled(false);
        users_table->setDragDropMode(QAbstractItemView::DragDrop);
        users_table->setDefaultDropAction(Qt::TargetMoveAction);
        users_table->setAlternatingRowColors(false);
        users_table->setSelectionMode(QAbstractItemView::SingleSelection);
        users_table->setSelectionBehavior(QAbstractItemView::SelectRows);
        users_table->setIconSize(QSize(24, 24));
        users_table->setGridStyle(Qt::DashDotLine);
        users_table->setSortingEnabled(true);
        users_table->horizontalHeader()->setCascadingSectionResizes(true);
        users_table->horizontalHeader()->setMinimumSectionSize(10);
        users_table->horizontalHeader()->setDefaultSectionSize(84);
        users_table->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        users_table->verticalHeader()->setCascadingSectionResizes(true);
        users_table->verticalHeader()->setMinimumSectionSize(10);
        users_table->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        users_table->verticalHeader()->setStretchLastSection(false);

        gridLayout_2->addWidget(users_table, 1, 0, 1, 1);

        update_users_Btn = new QPushButton(frame);
        update_users_Btn->setObjectName(QString::fromUtf8("update_users_Btn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(update_users_Btn->sizePolicy().hasHeightForWidth());
        update_users_Btn->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(update_users_Btn, 0, 0, 1, 1);

        frame1 = new QFrame(frame);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        sizePolicy.setHeightForWidth(frame1->sizePolicy().hasHeightForWidth());
        frame1->setSizePolicy(sizePolicy);
        frame1->setFrameShape(QFrame::StyledPanel);
        gridLayout_3 = new QGridLayout(frame1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(frame1);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(37, 17));

        gridLayout_3->addWidget(label, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label_6 = new QLabel(frame1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setTextFormat(Qt::AutoText);
        label_6->setWordWrap(true);

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1, Qt::AlignTop);

        groupBox_2 = new QGroupBox(frame1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_8);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_7);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_9);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_10);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout->setWidget(3, QFormLayout::FieldRole, label_11);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_12);


        gridLayout_3->addWidget(groupBox_2, 0, 1, 3, 1);


        gridLayout_2->addWidget(frame1, 0, 1, 3, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(UsersList);

        QMetaObject::connectSlotsByName(UsersList);
    } // setupUi

    void retranslateUi(QWidget *UsersList)
    {
        UsersList->setWindowTitle(QCoreApplication::translate("UsersList", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = users_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("UsersList", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = users_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("UsersList", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = users_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("UsersList", "Role", nullptr));
        update_users_Btn->setText(QCoreApplication::translate("UsersList", "Update", nullptr));
        label->setText(QCoreApplication::translate("UsersList", "Image", nullptr));
        label_6->setText(QCoreApplication::translate("UsersList", "<html><head/><body style=\"line-height:0.5; \"><h2 style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\"font-size:20pt; font-weight:700;\">Resume</span></h2><p><span style=\" font-weight:700;\">Bla very good dude</span></p><p>Bla Foo Bar</p></body></html>", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("UsersList", "Employee", nullptr));
        label_2->setText(QCoreApplication::translate("UsersList", "Name", nullptr));
        label_8->setText(QCoreApplication::translate("UsersList", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("UsersList", "Entry date", nullptr));
        label_9->setText(QCoreApplication::translate("UsersList", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("UsersList", "Role", nullptr));
        label_10->setText(QCoreApplication::translate("UsersList", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("UsersList", "Login", nullptr));
        label_11->setText(QCoreApplication::translate("UsersList", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("UsersList", "Password", nullptr));
        label_12->setText(QCoreApplication::translate("UsersList", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsersList: public Ui_UsersList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSLIST_H
