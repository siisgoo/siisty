/********************************************************************************
** Form generated from reading UI file 'RegisterAccidentDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERACCIDENTDIALOG_H
#define UI_REGISTERACCIDENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterAccidentDialog
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QLabel *label_6;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QFrame *line;
    QLabel *label_8;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox;
    QListWidget *listWidget;
    QLabel *label_5;
    QPushButton *pushButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RegisterAccidentDialog)
    {
        if (RegisterAccidentDialog->objectName().isEmpty())
            RegisterAccidentDialog->setObjectName(QString::fromUtf8("RegisterAccidentDialog"));
        RegisterAccidentDialog->resize(400, 300);
        gridLayout = new QGridLayout(RegisterAccidentDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(RegisterAccidentDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_6);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 0, 3, 1, 1);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 0, 2, 1, 1);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 0, 4, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(frame);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout_3->addWidget(doubleSpinBox, 0, 1, 1, 1);


        formLayout->setLayout(3, QFormLayout::SpanningRole, gridLayout_3);

        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        formLayout->setWidget(5, QFormLayout::SpanningRole, listWidget);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        formLayout->setWidget(4, QFormLayout::FieldRole, pushButton);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(RegisterAccidentDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Discard|QDialogButtonBox::Save);

        gridLayout->addWidget(buttonBox, 4, 0, 1, 1);


        retranslateUi(RegisterAccidentDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, RegisterAccidentDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, RegisterAccidentDialog, qOverload<>(&QDialog::reject));

        listWidget->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(RegisterAccidentDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterAccidentDialog)
    {
        RegisterAccidentDialog->setWindowTitle(QCoreApplication::translate("RegisterAccidentDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RegisterAccidentDialog", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterAccidentDialog", "Contract", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterAccidentDialog", "Used ammo", nullptr));
        label_6->setText(QCoreApplication::translate("RegisterAccidentDialog", "0", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterAccidentDialog", "Damage price", nullptr));
        label_8->setText(QCoreApplication::translate("RegisterAccidentDialog", "Base damage price", nullptr));
        label_7->setText(QCoreApplication::translate("RegisterAccidentDialog", "0", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterAccidentDialog", "Assigned employees", nullptr));
        pushButton->setText(QCoreApplication::translate("RegisterAccidentDialog", "add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterAccidentDialog: public Ui_RegisterAccidentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERACCIDENTDIALOG_H
