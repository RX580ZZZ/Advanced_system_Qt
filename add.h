#ifndef ADD_H
#define ADD_H

#include <QMainWindow>
#include <QButtonGroup>
#include<iostream>
#include<fstream>
#include <QHeaderView>
#include <QStandardItemModel>
#include<QMessageBox>
#include"Admin.h"
#include<vector>

extern Admin my_admin;

namespace Ui {
class add;
}

class add : public QMainWindow
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();

private slots:
    void on_pushButtonClose_clicked();

    void on_pushButtonFinish_clicked();

    void on_actionquit_triggered();

    void on_pushButtonConfirm_clicked();

private:
    Ui::add *ui;
    int left;
    string name;
    string major;
    string num;
    int classnum;
    int nums;
    vector<course_condition> cd;
};

#endif // ADD_AND_CHANGE_H
