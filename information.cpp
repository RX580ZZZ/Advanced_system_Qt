#include "information.h"
#include "ui_information.h"
#include "Admin.h"
#include "findcourseinfo.h"
#include"change.h"
#include"add.h"
#include <QButtonGroup>
#include<iostream>
#include<fstream>
#include<string>
#include <QHeaderView>
#include <QStandardItemModel>
#include<QMessageBox>
#include<QDebug>
#include<QString>

extern Admin my_admin;

Information::Information(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
    this->setWindowTitle("高级学生信息管理系统");

    on_pushButtonRefresh_clicked();
    on_pushButtonRefresh2_clicked();
}

Information::~Information()
{
    delete ui;
}

void Information::on_actionquit_triggered()
{
    close();
}

void Information::on_pushButtonSearch_clicked()
{
    if (ui->radioButtonVague->isChecked()){
        string temp = ui->lineEditSearch->text().toStdString();
        int ret;
        my_admin.Vague_Search(temp, ret);
    }
    else if (ui->radioButtonAdvanced->isChecked()){
        string s = ui->lineEditSearch->text().toStdString();
        int slen = s.size();
        int p = 0;
        string temp;
        int tp = 0;
        bool isand = false;
        bool isequal = false;
        bool first = true;
        int n = 0;
        int l = 0;
        int judge = -1;
        while (p < slen) {
            if (s[p] == '"') {
                int ret = 0;
                string expr;
                int ep = 0;
                p++;
                while (s[p] != '"' && p != slen) { //读取表达式
                    if (s[p] != ' ') { //空格忽略
                        expr.push_back(s[p]);
                        //expr[ep] = s[p];
                        ep++;
                    }
                    p++;
                }

                if (p == slen) { // 引号不匹配
                    QMessageBox::about(NULL,"错误", "输入的表达式有误");
                    my_admin.cleartemp();
                    return;
                }
                reguexpr my_regu(expr, ret);
                if (ret == -1) {
                    QMessageBox::about(NULL,"错误", "输入的表达式有误");
                    my_admin.cleartemp();
                    return;
                }
                //qDebug() <<  QString::fromStdString(temp) << temp.size();
                if (temp == "学号") n = 1;
                else if (temp == "姓名") n = 2;
                else if (temp == "院系") n = 3;
                else if (temp == "选课") n = 4;
                else if (temp == "班级") {
                    n = 5; l = atoi(expr.c_str());
                }
                else { //选项输入不正确
                    QMessageBox::about(NULL,"错误", "输入的表达式有误");
                    //qDebug() << QString::fromStdString(temp);
                    my_admin.cleartemp();
                    return;
                }

                my_admin.Advanced_Search(expr, n, l, isand, isequal, first);
                //qDebug() << QString::fromStdString(expr) << n << l << isand << isequal << first;
                if (first == true) first = false;
                judge = tp; isand = false;
            }
            else if (s[p] == '!'){ //不等于
                p++; isequal = false;
            }
            else if (s[p] == '=') { //等于
                isequal = true;
            }
            else if (s[p] == '&') {
                p++; isand = true;
            }
            else if (s[p] == '|') {
                p++; isand = false;
            }
            else if (s[p] != ' '){ //读入选项, 空格直接忽略
                if (tp == judge) {
                    judge = -1;
                    temp.clear();
                    tp = 0;
                    isequal = false;
                    n = 0;
                    l = 0;
                }

                //temp[tp] = s[p];
                temp.push_back(s[p]);
                tp++;
                //qDebug() << QString::fromStdString(temp) << s[p] << temp[tp - 1] << tp;
            }
            p++;
        }
    }
    else {
        QMessageBox::about(NULL,"错误", "请选择搜索方式");
        return;
    }

    if (my_admin._temp.size() == 0){
        QMessageBox::about(NULL,"提示", "未找到满足搜索条件的对象");
    }
    else{
        model_s = new QStandardItemModel();
        model_s->setHorizontalHeaderLabels({"学号", "姓名", "院系", "班级", "选课数"});

        int len = my_admin._temp.size();
        for (int i = 0; i < len; i++){
            model_s->setItem(i, 0, new QStandardItem(QString::fromStdString(my_admin._temp[i]._num)));
            model_s->setItem(i, 1, new QStandardItem(QString::fromStdString(my_admin._temp[i]._name)));
            model_s->setItem(i, 2, new QStandardItem(QString::fromStdString(my_admin._temp[i]._major)));
            model_s->setItem(i, 3, new QStandardItem(QString::fromStdString(std::to_string(my_admin._temp[i]._class))));
            model_s->setItem(i, 4, new QStandardItem(QString::fromStdString(std::to_string(my_admin._temp[i]._nums))));
        }

        ui->tableView->setModel(model_s);
    }

    my_admin.cleartemp();
}

void Information::on_pushButtonRefresh_clicked()
{
    model_s = new QStandardItemModel();
    model_s->setHorizontalHeaderLabels({"学号", "姓名", "院系", "班级", "选课数"});

    int len = my_admin._students.size();
    for (int i = 0; i < len; i++){
        model_s->setItem(i, 0, new QStandardItem(QString::fromStdString(my_admin._students[i]._num)));
        model_s->setItem(i, 1, new QStandardItem(QString::fromStdString(my_admin._students[i]._name)));
        model_s->setItem(i, 2, new QStandardItem(QString::fromStdString(my_admin._students[i]._major)));
        model_s->setItem(i, 3, new QStandardItem(QString::fromStdString(std::to_string(my_admin._students[i]._class))));
        model_s->setItem(i, 4, new QStandardItem(QString::fromStdString(std::to_string(my_admin._students[i]._nums))));
    }

    ui->tableView->setModel(model_s);
    on_pushButtonRefresh2_clicked();
}

void Information::on_pushButtonOpen_clicked()
{
    ifstream in_file;
    string filename = ui->lineEditOpen->text().toStdString();
    in_file.open(filename, ios::in);
    if (!in_file) {
        QMessageBox::about(NULL,"错误", "未能找到输入的文件名");
        return;
    }

    my_admin.Read_info_from_file(in_file);
    QMessageBox::about(NULL,"提示", "读取完成");

    on_pushButtonRefresh_clicked();
}

void Information::on_pushButtonSave_clicked()
{
    ofstream out_file;
    string filename = ui->lineEditSave->text().toStdString();
    out_file.open(filename, ios::out);
    if (!out_file) {
        QMessageBox::about(NULL,"错误", "未能找到输入的文件名");
        return;
    }

    my_admin.Save_Info_to_file(out_file, 0 ,true);
    QMessageBox::about(NULL,"提示", "保存完成");
}

void Information::on_pushButtonDel_clicked()
{
    string num = ui->lineEditDelete->text().toStdString();

    if (my_admin.hasStu(num) == false){
        QMessageBox::about(NULL,"错误", "要删除的学号不存在");
        return;
    }

    my_admin.Delete_student(num);
    QMessageBox::about(NULL,"提示", "删除成功");

    on_pushButtonRefresh_clicked();
}

void Information::on_pushButtonRefresh2_clicked()
{
    model_c = new QStandardItemModel();
    model_c->setHorizontalHeaderLabels({"课程号", "人数", "平均分"});

    int len = my_admin._courses.size();
    for (int i = 0; i < len; i++){
        model_c->setItem(i, 0, new QStandardItem(QString::fromStdString(my_admin._courses[i]._num)));
        model_c->setItem(i, 1, new QStandardItem(QString::fromStdString(to_string(my_admin._courses[i]._stus))));
        model_c->setItem(i, 2, new QStandardItem(QString::fromStdString(to_string(my_admin._courses[i].get_avg_score()))));
    }

    ui->tableView_2->setModel(model_c);
}

void Information::on_pushButtonFind_clicked()
{
    FindCourseInfo* find = new FindCourseInfo;
    find->show();
}


void Information::on_pushButtonAdd_clicked()
{
    add* addscene = new add;
    addscene->show();
    on_pushButtonRefresh_clicked();
}

void Information::on_pushButtonChange_clicked()
{
    change* changescene = new change;
    changescene->show();
    on_pushButtonRefresh_clicked();
}
