#pragma once
#include "Course.h"
#include"Student.h"
#include<vector>
using namespace std;

class reguexpr {
private:
    char* head;
    char* head_b;
	int head_p;
    char* tail;
    char* tail_b;
	int tail_p;
    bool ishead;
    bool istail;

public:
    reguexpr(string expr, int& ret);
    bool match(string expr);
};
