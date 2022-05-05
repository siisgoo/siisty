/********************************************************************************
** Form generated from reading UI file 'WelcomePage.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEPAGE_H
#define UI_WELCOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomePage
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *WelcomePage)
    {
        if (WelcomePage->objectName().isEmpty())
            WelcomePage->setObjectName(QString::fromUtf8("WelcomePage"));
        WelcomePage->resize(610, 471);
        WelcomePage->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(WelcomePage);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 2);
        frame = new QFrame(WelcomePage);
        frame->setObjectName(QString::fromUtf8("frame"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Anonymous Pro")});
        frame->setFont(font);
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pushButton, 3, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Monaco")});
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
""));
        label->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Monaco")});
        font2.setBold(false);
        label_2->setFont(font2);
        label_2->setTextFormat(Qt::MarkdownText);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2->setWordWrap(true);
        label_2->setMargin(2);
        label_2->setIndent(-1);
        label_2->setOpenExternalLinks(true);
        label_2->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);


        gridLayout->addWidget(frame, 2, 0, 1, 1);

#if QT_CONFIG(shortcut)
#endif // QT_CONFIG(shortcut)

        retranslateUi(WelcomePage);

        QMetaObject::connectSlotsByName(WelcomePage);
    } // setupUi

    void retranslateUi(QWidget *WelcomePage)
    {
        WelcomePage->setWindowTitle(QCoreApplication::translate("WelcomePage", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("WelcomePage", "Open setup page", nullptr));
        label->setText(QCoreApplication::translate("WelcomePage", "Welcome to sIIsTy Server manager", nullptr));
        label_2->setText(QCoreApplication::translate("WelcomePage", "<html><head/><body><p>sIIsTy server (<span style=\" font-style:italic;\">iiServer</span>) its a part of sIIsTy packet.</p><p>That program provides a server thats control database, now using <span style=\" font-style:italic;\">SQLite v3 stable</span>. This modification serve the Private Security Company (<span style=\" font-style:italic;\">PSC</span>).</p><p>Main purpose is a serve client connections and give clients access to database consider the client <span style=\" font-style:italic;\">Role</span>.</p><p>iiServer also take care about securty connections support by use optional <span style=\" font-weight:700;\">SSL</span>/<span style=\" font-weight:700;\">TLS</span>.</p><p>Right to access the database is static and built-in program but mirrored into database. Right system based on Roles system thats determines commands thats able to executed in server per each Role. To change its, download the <a href=\"https://github.com/siisgoo/siisty\"><span style=\" text-decoration: underline; color:#007af4;\">source co"
                        "de</span></a> and make changes consider the <span style=\" font-style:italic;\">README.md</span>.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomePage: public Ui_WelcomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEPAGE_H
