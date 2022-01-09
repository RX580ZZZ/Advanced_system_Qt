/********************************************************************************
** Form generated from reading UI file 'add.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_H
#define UI_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add
{
public:
    QAction *actionquit;
    QWidget *centralwidget;
    QLineEdit *lineEditNum;
    QLabel *label;
    QLineEdit *lineEditName;
    QLabel *label_2;
    QLineEdit *lineEditMajor;
    QLabel *label_3;
    QLineEdit *lineEditClass;
    QLabel *label_4;
    QLineEdit *lineEditNums;
    QLabel *label_5;
    QPushButton *pushButtonFinish;
    QPushButton *pushButtonClose;
    QLineEdit *lineEditCnum;
    QLineEdit *lineEditScore;
    QPushButton *pushButtonConfirm;
    QLabel *label_6;
    QLabel *label_7;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *add)
    {
        if (add->objectName().isEmpty())
            add->setObjectName(QString::fromUtf8("add"));
        add->resize(800, 600);
        actionquit = new QAction(add);
        actionquit->setObjectName(QString::fromUtf8("actionquit"));
        centralwidget = new QWidget(add);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEditNum = new QLineEdit(centralwidget);
        lineEditNum->setObjectName(QString::fromUtf8("lineEditNum"));
        lineEditNum->setGeometry(QRect(250, 100, 181, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 90, 91, 31));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        lineEditName = new QLineEdit(centralwidget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(250, 170, 181, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 160, 91, 31));
        label_2->setFont(font);
        lineEditMajor = new QLineEdit(centralwidget);
        lineEditMajor->setObjectName(QString::fromUtf8("lineEditMajor"));
        lineEditMajor->setGeometry(QRect(250, 240, 181, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 230, 91, 31));
        label_3->setFont(font);
        lineEditClass = new QLineEdit(centralwidget);
        lineEditClass->setObjectName(QString::fromUtf8("lineEditClass"));
        lineEditClass->setGeometry(QRect(250, 310, 181, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 300, 91, 31));
        label_4->setFont(font);
        lineEditNums = new QLineEdit(centralwidget);
        lineEditNums->setObjectName(QString::fromUtf8("lineEditNums"));
        lineEditNums->setGeometry(QRect(250, 380, 181, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(130, 370, 91, 31));
        label_5->setFont(font);
        pushButtonFinish = new QPushButton(centralwidget);
        pushButtonFinish->setObjectName(QString::fromUtf8("pushButtonFinish"));
        pushButtonFinish->setGeometry(QRect(180, 450, 201, 71));
        QFont font1;
        font1.setPointSize(20);
        pushButtonFinish->setFont(font1);
        pushButtonClose = new QPushButton(centralwidget);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(450, 450, 201, 71));
        pushButtonClose->setFont(font1);
        lineEditCnum = new QLineEdit(centralwidget);
        lineEditCnum->setObjectName(QString::fromUtf8("lineEditCnum"));
        lineEditCnum->setGeometry(QRect(600, 130, 141, 21));
        lineEditScore = new QLineEdit(centralwidget);
        lineEditScore->setObjectName(QString::fromUtf8("lineEditScore"));
        lineEditScore->setGeometry(QRect(600, 200, 141, 21));
        pushButtonConfirm = new QPushButton(centralwidget);
        pushButtonConfirm->setObjectName(QString::fromUtf8("pushButtonConfirm"));
        pushButtonConfirm->setGeometry(QRect(620, 260, 93, 28));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(510, 130, 72, 15));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(530, 200, 72, 15));
        add->setCentralWidget(centralwidget);
        menubar = new QMenuBar(add);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        add->setMenuBar(menubar);
        statusbar = new QStatusBar(add);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        add->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionquit);

        retranslateUi(add);

        QMetaObject::connectSlotsByName(add);
    } // setupUi

    void retranslateUi(QMainWindow *add)
    {
        add->setWindowTitle(QCoreApplication::translate("add", "MainWindow", nullptr));
        actionquit->setText(QCoreApplication::translate("add", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("add", "\345\255\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("add", "\345\247\223\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("add", "\344\270\223\344\270\232", nullptr));
        label_4->setText(QCoreApplication::translate("add", "\347\217\255\347\272\247", nullptr));
        label_5->setText(QCoreApplication::translate("add", "\351\200\211\350\257\276\346\225\260", nullptr));
        pushButtonFinish->setText(QCoreApplication::translate("add", "\345\256\214\346\210\220", nullptr));
        pushButtonClose->setText(QCoreApplication::translate("add", "\345\205\263\351\227\255", nullptr));
        pushButtonConfirm->setText(QCoreApplication::translate("add", "\347\241\256\350\256\244", nullptr));
        label_6->setText(QCoreApplication::translate("add", "\350\257\276\347\250\213\347\274\226\345\217\267", nullptr));
        label_7->setText(QCoreApplication::translate("add", "\346\210\220\347\273\251", nullptr));
        menu->setTitle(QCoreApplication::translate("add", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add: public Ui_add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
