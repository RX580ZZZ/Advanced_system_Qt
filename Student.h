#pragma once
#include<vector>
#include<string>
using namespace std;

struct course_condition {
    string _course_num; //课程编号
	int _score; //成绩
};
class Student {
	
private:
    string _name; //姓名
    string _major; //院系
    string _num; //学号
	int _class; //班级
	int _nums;//选修课程数
	vector <course_condition> _courses; //课程情况
public:
	friend class Admin;
    friend class Information;
    friend class add;
    friend class FindCourseInfo;
    friend class change;
    Student() {_class = 0; _nums = 0; };
};
