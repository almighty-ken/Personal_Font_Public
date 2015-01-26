/********************************************************************************
** Form generated from reading UI file 'capture.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTURE_H
#define UI_CAPTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CaptureClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QPushButton *pushButton_5;
    QSpinBox *spinBox;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_7;
    QSpinBox *spinBox_2;
    QLabel *label_9;
    QLCDNumber *lcdNumber;
    QLabel *label_10;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;

    void setupUi(QMainWindow *CaptureClass)
    {
        if (CaptureClass->objectName().isEmpty())
            CaptureClass->setObjectName(QStringLiteral("CaptureClass"));
        CaptureClass->resize(779, 669);
        centralWidget = new QWidget(CaptureClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 30, 141, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\350\220\235\350\216\211\344\275\223-DDC.yolan"));
        font.setPointSize(14);
        pushButton->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 60, 500, 500));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\350\220\235\350\216\211\344\275\223-DDC.yolan"));
        font1.setPointSize(16);
        label->setFont(font1);
        label->setFrameShape(QFrame::Box);
        label->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 70, 141, 31));
        pushButton_2->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 480, 141, 141));
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(580, 600, 90, 40));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(700, 10, 66, 648));
        label_3->setFrameShape(QFrame::Box);
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 370, 141, 31));
        pushButton_5->setFont(font);
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(50, 410, 81, 22));
        spinBox->setMaximum(4000);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(480, 600, 90, 40));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(380, 600, 90, 40));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 500, 28, 28));
        label_4->setFrameShape(QFrame::NoFrame);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(48, 500, 28, 28));
        label_5->setFrameShape(QFrame::NoFrame);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(76, 500, 28, 28));
        label_6->setFrameShape(QFrame::NoFrame);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(104, 500, 28, 28));
        label_7->setFrameShape(QFrame::NoFrame);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(132, 500, 28, 28));
        label_8->setFrameShape(QFrame::NoFrame);
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(280, 600, 90, 40));
        spinBox_2 = new QSpinBox(centralWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(50, 160, 81, 22));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(3750);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 130, 171, 31));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(50, 310, 81, 41));
        lcdNumber->setDigitCount(4);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 270, 121, 41));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(20, 190, 141, 31));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(20, 240, 141, 31));
        CaptureClass->setCentralWidget(centralWidget);

        retranslateUi(CaptureClass);
        QObject::connect(pushButton, SIGNAL(clicked()), CaptureClass, SLOT(slot1()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), CaptureClass, SLOT(slot1()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), CaptureClass, SLOT(slot2()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), CaptureClass, SLOT(result_output()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), CaptureClass, SLOT(again()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), CaptureClass, SLOT(back()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), CaptureClass, SLOT(Full_Scope()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), CaptureClass, SLOT(Change_Thread()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), CaptureClass, SLOT(make_one()));

        QMetaObject::connectSlotsByName(CaptureClass);
    } // setupUi

    void retranslateUi(QMainWindow *CaptureClass)
    {
        CaptureClass->setWindowTitle(QApplication::translate("CaptureClass", "Capture", 0));
        pushButton->setText(QApplication::translate("CaptureClass", "\351\226\213\345\247\213\350\256\200\345\217\226\346\250\243\346\234\254", 0));
        label->setText(QApplication::translate("CaptureClass", "no image load", 0));
        pushButton_2->setText(QApplication::translate("CaptureClass", "\351\200\262\350\241\214\347\265\204\345\255\227", 0));
        label_2->setText(QString());
        pushButton_3->setText(QApplication::translate("CaptureClass", "Next", 0));
        label_3->setText(QString());
        pushButton_5->setText(QApplication::translate("CaptureClass", "\350\274\270\345\207\272\347\265\204\345\255\227\347\265\220\346\236\234", 0));
        pushButton_4->setText(QApplication::translate("CaptureClass", "Again", 0));
        pushButton_6->setText(QApplication::translate("CaptureClass", "Back", 0));
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        pushButton_7->setText(QApplication::translate("CaptureClass", "\345\205\250\345\237\237\347\211\271\345\276\265", 0));
        label_9->setText(QApplication::translate("CaptureClass", "\345\276\236\347\211\271\345\256\232\347\267\250\350\231\237\351\226\213\345\247\213\350\274\270\345\205\245\357\274\232", 0));
        label_10->setText(QApplication::translate("CaptureClass", "\347\217\276\345\234\250\350\256\200\345\217\226\347\267\250\350\231\237\357\274\232", 0));
        pushButton_8->setText(QApplication::translate("CaptureClass", "\347\211\271\345\256\232\347\267\250\350\231\237\351\226\213\345\247\213\357\274\232", 0));
        pushButton_9->setText(QApplication::translate("CaptureClass", "\347\211\271\345\256\232\347\267\250\350\231\237\347\265\204\345\255\227", 0));
    } // retranslateUi

};

namespace Ui {
    class CaptureClass: public Ui_CaptureClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTURE_H
