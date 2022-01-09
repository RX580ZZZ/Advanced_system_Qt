#ifndef FINDCOURSEINFO_H
#define FINDCOURSEINFO_H

#include <QMainWindow>
#include<QStandardItem>

namespace Ui {
class FindCourseInfo;
}

class FindCourseInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit FindCourseInfo(QWidget *parent = nullptr);
    ~FindCourseInfo();

private slots:
    void on_actionquit_triggered();

    void on_pushButton_clicked();

private:
    Ui::FindCourseInfo *ui;
    QStandardItemModel* model;
};

#endif // FINDCOURSEINFO_H
