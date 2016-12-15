/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Jul 5 11:55:47 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *insert;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *time;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *leftLeg;
    QLineEdit *rightLeg;
    QLabel *label_8;
    QLabel *label_9;
    QGroupBox *groupBox_3;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *rightHand;
    QLineEdit *leftHand;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *head;
    QPlainTextEdit *yamlPre;
    QLabel *label_14;
    QPushButton *create;
    QLabel *label_12;
    QMenuBar *menuBar;
    QMenu *menuSpecial_Action_Yaml_Config_Creator;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(675, 727);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        insert = new QPushButton(centralWidget);
        insert->setObjectName(QString::fromUtf8("insert"));
        insert->setGeometry(QRect(380, 330, 121, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 24, 66, 17));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 310, 66, 17));
        time = new QLineEdit(centralWidget);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(70, 20, 121, 27));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 70, 641, 101));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 66, 17));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 91, 17));
        leftLeg = new QLineEdit(groupBox);
        leftLeg->setObjectName(QString::fromUtf8("leftLeg"));
        leftLeg->setGeometry(QRect(60, 30, 171, 27));
        QFont font;
        font.setPointSize(11);
        leftLeg->setFont(font);
        leftLeg->setMaxLength(32767);
        rightLeg = new QLineEdit(groupBox);
        rightLeg->setObjectName(QString::fromUtf8("rightLeg"));
        rightLeg->setGeometry(QRect(60, 70, 171, 27));
        rightLeg->setFont(font);
        rightLeg->setMaxLength(32767);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(236, 33, 411, 17));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(235, 74, 411, 17));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 180, 581, 101));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 40, 66, 17));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 80, 61, 17));
        rightHand = new QLineEdit(groupBox_3);
        rightHand->setObjectName(QString::fromUtf8("rightHand"));
        rightHand->setGeometry(QRect(60, 70, 121, 27));
        rightHand->setFont(font);
        rightHand->setMaxLength(32767);
        leftHand = new QLineEdit(groupBox_3);
        leftHand->setObjectName(QString::fromUtf8("leftHand"));
        leftHand->setGeometry(QRect(60, 40, 121, 27));
        leftHand->setFont(font);
        leftHand->setMaxLength(32767);
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(190, 43, 281, 17));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(191, 74, 281, 17));
        head = new QLineEdit(centralWidget);
        head->setObjectName(QString::fromUtf8("head"));
        head->setGeometry(QRect(70, 300, 121, 27));
        head->setFont(font);
        head->setMaxLength(32767);
        yamlPre = new QPlainTextEdit(centralWidget);
        yamlPre->setObjectName(QString::fromUtf8("yamlPre"));
        yamlPre->setEnabled(true);
        yamlPre->setGeometry(QRect(20, 400, 631, 261));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(30, 360, 241, 17));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_14->setFont(font1);
        create = new QPushButton(centralWidget);
        create->setObjectName(QString::fromUtf8("create"));
        create->setGeometry(QRect(530, 330, 121, 27));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(200, 303, 101, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 675, 25));
        menuSpecial_Action_Yaml_Config_Creator = new QMenu(menuBar);
        menuSpecial_Action_Yaml_Config_Creator->setObjectName(QString::fromUtf8("menuSpecial_Action_Yaml_Config_Creator"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(time, leftLeg);
        QWidget::setTabOrder(leftLeg, rightLeg);
        QWidget::setTabOrder(rightLeg, leftHand);
        QWidget::setTabOrder(leftHand, rightHand);
        QWidget::setTabOrder(rightHand, head);
        QWidget::setTabOrder(head, insert);

        menuBar->addAction(menuSpecial_Action_Yaml_Config_Creator->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Special Action Yaml Config Creator", 0, QApplication::UnicodeUTF8));
        insert->setText(QApplication::translate("MainWindow", "Insert Kick Point", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Time = ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Head", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Legs", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        leftLeg->setInputMask(QString());
        leftLeg->setText(QString());
        rightLeg->setInputMask(QString());
        rightLeg->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "[HipYaw, HipRoll, HipPitch, KneePitch, AnklePitch, AnkleRoll]", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "[HipYaw, HipRoll, HipPitch, KneePitch, AnklePitch, AnkleRoll]", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Hands", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        rightHand->setInputMask(QString());
        rightHand->setText(QString());
        leftHand->setInputMask(QString());
        leftHand->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "[ShoulderPitch, ShoulderRoll,ElbowPitch] ", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "[ShoulderPitch, ShoulderRoll,ElbowPitch] ", 0, QApplication::UnicodeUTF8));
        head->setInputMask(QString());
        head->setText(QString());
        yamlPre->setPlainText(QString());
        label_14->setText(QApplication::translate("MainWindow", "Kick Points Yaml Config Preview", 0, QApplication::UnicodeUTF8));
        create->setText(QApplication::translate("MainWindow", "Create Yaml File", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "[Pitch, Yaw] ", 0, QApplication::UnicodeUTF8));
        menuSpecial_Action_Yaml_Config_Creator->setTitle(QApplication::translate("MainWindow", "Special Action Yaml Config Creator", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
