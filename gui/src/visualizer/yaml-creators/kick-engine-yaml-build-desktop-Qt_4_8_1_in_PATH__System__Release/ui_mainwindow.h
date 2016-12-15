/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Jul 5 12:13:26 2014
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
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *swingPos;
    QLineEdit *swingRot;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *time;
    QPushButton *insert;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *comRot;
    QLineEdit *comPos;
    QLabel *label_10;
    QPushButton *create;
    QGroupBox *groupBox_3;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *rightHand;
    QLineEdit *leftHand;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_14;
    QPlainTextEdit *yamlPre;
    QLabel *label_11;
    QMenuBar *menuBar;
    QMenu *menuKick_Engine_Yaml_Config_Creator;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(702, 791);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 66, 17));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 50, 331, 101));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 66, 17));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 91, 17));
        swingPos = new QLineEdit(groupBox);
        swingPos->setObjectName(QString::fromUtf8("swingPos"));
        swingPos->setGeometry(QRect(100, 30, 121, 27));
        QFont font;
        font.setPointSize(11);
        swingPos->setFont(font);
        swingPos->setMaxLength(32767);
        swingRot = new QLineEdit(groupBox);
        swingRot->setObjectName(QString::fromUtf8("swingRot"));
        swingRot->setGeometry(QRect(100, 60, 121, 27));
        swingRot->setFont(font);
        swingRot->setMaxLength(32767);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(230, 35, 66, 17));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(228, 67, 111, 17));
        time = new QLineEdit(centralWidget);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(120, 14, 121, 27));
        insert = new QPushButton(centralWidget);
        insert->setObjectName(QString::fromUtf8("insert"));
        insert->setGeometry(QRect(380, 280, 121, 27));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(360, 50, 311, 101));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 40, 66, 17));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 70, 91, 17));
        comRot = new QLineEdit(groupBox_2);
        comRot->setObjectName(QString::fromUtf8("comRot"));
        comRot->setGeometry(QRect(110, 60, 121, 27));
        comRot->setFont(font);
        comRot->setMaxLength(32767);
        comPos = new QLineEdit(groupBox_2);
        comPos->setObjectName(QString::fromUtf8("comPos"));
        comPos->setGeometry(QRect(110, 30, 121, 27));
        comPos->setFont(font);
        comPos->setMaxLength(32767);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(236, 35, 66, 17));
        create = new QPushButton(centralWidget);
        create->setObjectName(QString::fromUtf8("create"));
        create->setGeometry(QRect(520, 280, 121, 27));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 160, 531, 101));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 40, 66, 17));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 80, 61, 17));
        rightHand = new QLineEdit(groupBox_3);
        rightHand->setObjectName(QString::fromUtf8("rightHand"));
        rightHand->setGeometry(QRect(100, 70, 121, 27));
        rightHand->setFont(font);
        rightHand->setMaxLength(32767);
        leftHand = new QLineEdit(groupBox_3);
        leftHand->setObjectName(QString::fromUtf8("leftHand"));
        leftHand->setGeometry(QRect(100, 40, 121, 27));
        leftHand->setFont(font);
        leftHand->setMaxLength(32767);
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(230, 40, 281, 17));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(233, 76, 281, 17));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(21, 297, 241, 17));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_14->setFont(font1);
        yamlPre = new QPlainTextEdit(centralWidget);
        yamlPre->setObjectName(QString::fromUtf8("yamlPre"));
        yamlPre->setGeometry(QRect(20, 320, 631, 401));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(595, 116, 111, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 702, 25));
        menuKick_Engine_Yaml_Config_Creator = new QMenu(menuBar);
        menuKick_Engine_Yaml_Config_Creator->setObjectName(QString::fromUtf8("menuKick_Engine_Yaml_Config_Creator"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(time, swingPos);
        QWidget::setTabOrder(swingPos, swingRot);
        QWidget::setTabOrder(swingRot, comPos);
        QWidget::setTabOrder(comPos, comRot);
        QWidget::setTabOrder(comRot, leftHand);
        QWidget::setTabOrder(leftHand, rightHand);
        QWidget::setTabOrder(rightHand, insert);
        QWidget::setTabOrder(insert, create);
        QWidget::setTabOrder(create, yamlPre);

        menuBar->addAction(menuKick_Engine_Yaml_Config_Creator->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Kick Engine Yaml Config Creator", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Time = ", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Stand Swing", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Position ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Orientation", 0, QApplication::UnicodeUTF8));
        swingPos->setInputMask(QString());
        swingPos->setText(QString());
        swingRot->setInputMask(QString());
        swingRot->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "[x, y, z]", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "[Roll,Pitch,Yaw]", 0, QApplication::UnicodeUTF8));
        insert->setText(QApplication::translate("MainWindow", "Insert Kick Point", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Stand COM", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Position ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Orientation", 0, QApplication::UnicodeUTF8));
        comRot->setInputMask(QString());
        comRot->setText(QString());
        comPos->setInputMask(QString());
        comPos->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "[x, y, z]", 0, QApplication::UnicodeUTF8));
        create->setText(QApplication::translate("MainWindow", "Create Yaml File", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Hands", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        rightHand->setInputMask(QString());
        rightHand->setText(QString());
        leftHand->setInputMask(QString());
        leftHand->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "[ShoulderPitch, ShoulderRoll,ElbowPitch] ", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "[ShoulderPitch, ShoulderRoll,ElbowPitch] ", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Kick Points Yaml Config Preview", 0, QApplication::UnicodeUTF8));
        yamlPre->setPlainText(QString());
        label_11->setText(QApplication::translate("MainWindow", "[Roll,Pitch,Yaw]", 0, QApplication::UnicodeUTF8));
        menuKick_Engine_Yaml_Config_Creator->setTitle(QApplication::translate("MainWindow", "Kick Engine Yaml Config Creator", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
