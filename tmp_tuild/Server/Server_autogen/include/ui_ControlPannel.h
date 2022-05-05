/********************************************************************************
** Form generated from reading UI file 'ControlPannel.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLPANNEL_H
#define UI_CONTROLPANNEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlPannel
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame_3;
    QGridLayout *gridLayout_5;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *frame_4;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *ControlPannel)
    {
        if (ControlPannel->objectName().isEmpty())
            ControlPannel->setObjectName(QString::fromUtf8("ControlPannel"));
        ControlPannel->resize(582, 403);
        gridLayout = new QGridLayout(ControlPannel);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(ControlPannel);
        frame->setObjectName(QString::fromUtf8("frame"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Anonymous Pro")});
        font.setItalic(true);
        frame->setFont(font);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);


        gridLayout_2->addWidget(frame_2, 0, 0, 1, 1);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_5->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_5->addWidget(label_6, 1, 0, 1, 1);


        gridLayout_2->addWidget(frame_3, 0, 1, 1, 1);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);


        gridLayout_2->addWidget(frame_4, 1, 0, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(ControlPannel);

        QMetaObject::connectSlotsByName(ControlPannel);
    } // setupUi

    void retranslateUi(QWidget *ControlPannel)
    {
        ControlPannel->setWindowTitle(QCoreApplication::translate("ControlPannel", "Form", nullptr));
        label->setText(QCoreApplication::translate("ControlPannel", "Service control", nullptr));
        label_2->setText(QCoreApplication::translate("ControlPannel", "Server and proxy settings", nullptr));
        label_5->setText(QCoreApplication::translate("ControlPannel", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("ControlPannel", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("ControlPannel", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("ControlPannel", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlPannel: public Ui_ControlPannel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPANNEL_H
