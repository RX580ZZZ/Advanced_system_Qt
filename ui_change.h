/********************************************************************************
** Form generated from reading UI file 'change.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_H
#define UI_CHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_change
{
public:
    QAction *actionquit;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLineEdit *lineEditT;
    QLineEdit *lineEditScore;
    QLabel *label_2;
    QRadioButton *radioButtonAdd;
    QRadioButton *radioButtonDel;
    QLabel *label_3;
    QLineEdit *lineEditNum;
    QLabel *label_4;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *change)
    {
        if (change->objectName().isEmpty())
            change->setObjectName(QString::fromUtf8("change"));
        change->resize(693, 297);
        actionquit = new QAction(change);
        actionquit->setObjectName(QString::fromUtf8("actionquit"));
        centralwidget = new QWidget(change);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 210, 93, 28));
        lineEditT = new QLineEdit(centralwidget);
        lineEditT->setObjectName(QString::fromUtf8("lineEditT"));
        lineEditT->setGeometry(QRect(300, 60, 191, 31));
        lineEditScore = new QLineEdit(centralwidget);
        lineEditScore->setObjectName(QString::fromUtf8("lineEditScore"));
        lineEditScore->setGeometry(QRect(530, 70, 113, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(560, 20, 121, 31));
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);
        radioButtonAdd = new QRadioButton(centralwidget);
        radioButtonAdd->setObjectName(QString::fromUtf8("radioButtonAdd"));
        radioButtonAdd->setGeometry(QRect(200, 130, 115, 19));
        radioButtonDel = new QRadioButton(centralwidget);
        radioButtonDel->setObjectName(QString::fromUtf8("radioButtonDel"));
        radioButtonDel->setGeometry(QRect(400, 130, 115, 19));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 160, 471, 31));
        lineEditNum = new QLineEdit(centralwidget);
        lineEditNum->setObjectName(QString::fromUtf8("lineEditNum"));
        lineEditNum->setGeometry(QRect(60, 60, 191, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 20, 91, 21));
        label_4->setFont(font);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(350, 20, 87, 22));
        change->setCentralWidget(centralwidget);
        menubar = new QMenuBar(change);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 693, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        change->setMenuBar(menubar);
        statusbar = new QStatusBar(change);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        change->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionquit);

        retranslateUi(change);

        QMetaObject::connectSlotsByName(change);
    } // setupUi

    void retranslateUi(QMainWindow *change)
    {
        change->setWindowTitle(QCoreApplication::translate("change", "MainWindow", nullptr));
        actionquit->setText(QCoreApplication::translate("change", "\351\200\200\345\207\272", nullptr));
        pushButton->setText(QCoreApplication::translate("change", "\347\241\256\350\256\244", nullptr));
        label_2->setText(QCoreApplication::translate("change", "\345\210\206\346\225\260", nullptr));
        radioButtonAdd->setText(QCoreApplication::translate("change", "\346\267\273\345\212\240/\344\277\256\346\224\271", nullptr));
        radioButtonDel->setText(QCoreApplication::translate("change", "\345\210\240\351\231\244", nullptr));
        label_3->setText(QCoreApplication::translate("change", "\344\277\256\346\224\271\351\200\211\350\257\276\344\277\241\346\201\257\346\227\266\350\257\267\351\200\211\346\213\251\346\267\273\345\212\240/\344\277\256\346\224\271\346\210\226\345\210\240\351\231\244\357\274\214\351\200\211\346\213\251\345\210\240\351\231\244\345\217\257\344\270\215\345\241\253\345\206\231\345\210\206\346\225\260", nullptr));
        label_4->setText(QCoreApplication::translate("change", "\345\255\246\345\217\267", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("change", "\345\247\223\345\220\215", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("change", "\351\231\242\347\263\273", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("change", "\347\217\255\347\272\247", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("change", "\351\200\211\350\257\276", nullptr));

        menu->setTitle(QCoreApplication::translate("change", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class change: public Ui_change {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_H
