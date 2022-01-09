/********************************************************************************
** Form generated from reading UI file 'information.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATION_H
#define UI_INFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Information
{
public:
    QAction *actionquit;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonSave;
    QLineEdit *lineEditSearch;
    QRadioButton *radioButtonVague;
    QRadioButton *radioButtonAdvanced;
    QPushButton *pushButtonFind;
    QPushButton *pushButtonSearch;
    QPushButton *pushButtonRefresh;
    QLineEdit *lineEditOpen;
    QLineEdit *lineEditSave;
    QLineEdit *lineEditDelete;
    QLabel *label;
    QPushButton *pushButtonChange;
    QWidget *tab_2;
    QTableView *tableView_2;
    QPushButton *pushButtonRefresh2;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Information)
    {
        if (Information->objectName().isEmpty())
            Information->setObjectName(QString::fromUtf8("Information"));
        Information->resize(800, 600);
        actionquit = new QAction(Information);
        actionquit->setObjectName(QString::fromUtf8("actionquit"));
        centralwidget = new QWidget(Information);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 801, 571));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 160, 611, 391));
        pushButtonAdd = new QPushButton(tab);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(650, 0, 93, 28));
        pushButtonDel = new QPushButton(tab);
        pushButtonDel->setObjectName(QString::fromUtf8("pushButtonDel"));
        pushButtonDel->setGeometry(QRect(650, 160, 93, 28));
        pushButtonOpen = new QPushButton(tab);
        pushButtonOpen->setObjectName(QString::fromUtf8("pushButtonOpen"));
        pushButtonOpen->setGeometry(QRect(650, 260, 91, 28));
        pushButtonSave = new QPushButton(tab);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(650, 380, 91, 28));
        lineEditSearch = new QLineEdit(tab);
        lineEditSearch->setObjectName(QString::fromUtf8("lineEditSearch"));
        lineEditSearch->setGeometry(QRect(70, 40, 291, 31));
        radioButtonVague = new QRadioButton(tab);
        radioButtonVague->setObjectName(QString::fromUtf8("radioButtonVague"));
        radioButtonVague->setGeometry(QRect(70, 100, 115, 19));
        radioButtonAdvanced = new QRadioButton(tab);
        radioButtonAdvanced->setObjectName(QString::fromUtf8("radioButtonAdvanced"));
        radioButtonAdvanced->setGeometry(QRect(210, 100, 115, 19));
        pushButtonFind = new QPushButton(tab);
        pushButtonFind->setObjectName(QString::fromUtf8("pushButtonFind"));
        pushButtonFind->setGeometry(QRect(630, 440, 141, 61));
        pushButtonSearch = new QPushButton(tab);
        pushButtonSearch->setObjectName(QString::fromUtf8("pushButtonSearch"));
        pushButtonSearch->setGeometry(QRect(400, 40, 93, 28));
        pushButtonRefresh = new QPushButton(tab);
        pushButtonRefresh->setObjectName(QString::fromUtf8("pushButtonRefresh"));
        pushButtonRefresh->setGeometry(QRect(430, 100, 93, 28));
        lineEditOpen = new QLineEdit(tab);
        lineEditOpen->setObjectName(QString::fromUtf8("lineEditOpen"));
        lineEditOpen->setGeometry(QRect(620, 220, 161, 21));
        lineEditSave = new QLineEdit(tab);
        lineEditSave->setObjectName(QString::fromUtf8("lineEditSave"));
        lineEditSave->setGeometry(QRect(622, 320, 161, 21));
        lineEditDelete = new QLineEdit(tab);
        lineEditDelete->setObjectName(QString::fromUtf8("lineEditDelete"));
        lineEditDelete->setGeometry(QRect(622, 120, 151, 21));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(360, 129, 131, 31));
        pushButtonChange = new QPushButton(tab);
        pushButtonChange->setObjectName(QString::fromUtf8("pushButtonChange"));
        pushButtonChange->setGeometry(QRect(650, 60, 93, 28));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tableView_2 = new QTableView(tab_2);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(0, 0, 611, 521));
        pushButtonRefresh2 = new QPushButton(tab_2);
        pushButtonRefresh2->setObjectName(QString::fromUtf8("pushButtonRefresh2"));
        pushButtonRefresh2->setGeometry(QRect(660, 70, 93, 28));
        tabWidget->addTab(tab_2, QString());
        Information->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Information);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Information->setMenuBar(menubar);
        statusbar = new QStatusBar(Information);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Information->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionquit);

        retranslateUi(Information);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Information);
    } // setupUi

    void retranslateUi(QMainWindow *Information)
    {
        Information->setWindowTitle(QCoreApplication::translate("Information", "MainWindow", nullptr));
        actionquit->setText(QCoreApplication::translate("Information", "\351\200\200\345\207\272", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("Information", "\346\267\273\345\212\240", nullptr));
        pushButtonDel->setText(QCoreApplication::translate("Information", "\345\210\240\351\231\244", nullptr));
        pushButtonOpen->setText(QCoreApplication::translate("Information", "\346\211\223\345\274\200", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("Information", "\344\277\235\345\255\230", nullptr));
        radioButtonVague->setText(QCoreApplication::translate("Information", "\346\250\241\347\263\212\346\220\234\347\264\242", nullptr));
        radioButtonAdvanced->setText(QCoreApplication::translate("Information", "\351\253\230\347\272\247\346\220\234\347\264\242", nullptr));
        pushButtonFind->setText(QCoreApplication::translate("Information", "\346\237\245\346\211\276\345\255\246\347\224\237\351\200\211\350\257\276", nullptr));
        pushButtonSearch->setText(QCoreApplication::translate("Information", "\346\220\234\347\264\242", nullptr));
        pushButtonRefresh->setText(QCoreApplication::translate("Information", "\345\210\267\346\226\260", nullptr));
        label->setText(QString());
        pushButtonChange->setText(QCoreApplication::translate("Information", "\344\277\256\346\224\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Information", "\345\255\246\347\224\237\344\277\241\346\201\257", nullptr));
        pushButtonRefresh2->setText(QCoreApplication::translate("Information", "\345\210\267\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Information", "\350\257\276\347\250\213\344\277\241\346\201\257", nullptr));
        menu->setTitle(QCoreApplication::translate("Information", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Information: public Ui_Information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATION_H
