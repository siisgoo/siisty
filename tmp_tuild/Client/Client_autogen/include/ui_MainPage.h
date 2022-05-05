/********************************************************************************
** Form generated from reading UI file 'MainPage.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QPushButton *userLogin;
    QPushButton *singup;

    void setupUi(QWidget *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName(QString::fromUtf8("MainPage"));
        MainPage->resize(337, 293);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainPage->sizePolicy().hasHeightForWidth());
        MainPage->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(MainPage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(MainPage);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        userLogin = new QPushButton(frame);
        userLogin->setObjectName(QString::fromUtf8("userLogin"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Monaco")});
        font.setPointSize(14);
        font.setItalic(false);
        userLogin->setFont(font);
        userLogin->setStyleSheet(QString::fromUtf8(""));
        userLogin->setIconSize(QSize(300, 218));

        verticalLayout->addWidget(userLogin);

        singup = new QPushButton(frame);
        singup->setObjectName(QString::fromUtf8("singup"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(singup->sizePolicy().hasHeightForWidth());
        singup->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(singup, 0, Qt::AlignHCenter);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(MainPage);

        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QWidget *MainPage)
    {
        MainPage->setWindowTitle(QCoreApplication::translate("MainPage", "Form", nullptr));
        userLogin->setText(QString());
        singup->setText(QCoreApplication::translate("MainPage", "sing up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
