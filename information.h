#ifndef INFORMATION_H
#define INFORMATION_H

#include <QMainWindow>
#include <QStandardItemModel>
#include"Student.h"
#include"Course.h"
#include"Admin.h"
#include"reguexpr.h"
#include"add.h"

namespace Ui {
class Information;
}

class Information : public QMainWindow
{
    Q_OBJECT

public:
    explicit Information(QWidget *parent = nullptr);
    ~Information();

private slots:
    void on_actionquit_triggered();

    void on_pushButtonSearch_clicked();

    void on_pushButtonRefresh_clicked();

    void on_pushButtonOpen_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonDel_clicked();

    void on_pushButtonRefresh2_clicked();

    void on_pushButtonFind_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonChange_clicked();

private:
    Ui::Information *ui;
    QStandardItemModel* model_s;
    QStandardItemModel* model_c;
};

#endif // INFORMATION_H
