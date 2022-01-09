#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include"reguexpr.h"
using namespace std;

reguexpr::reguexpr(string expr, int& ret) {
	ret = 0;
    int len = expr.size();
    head = new char[len + 1];
	memset(head, 0, sizeof(char) * (len + 1));
	head_b = new char[len + 1];
	memset(head_b, 0, sizeof(char) * (len + 1));
	tail = new char[len + 1];
	memset(tail, 0, sizeof(char) * (len + 1));
	tail_b = new char[len + 1];
	memset(tail_b, 0, sizeof(char) * (len + 1));

	head_p = 0;
	tail_p = 0;
	ishead = false;
	istail = false;
    int leftnum = 0;
    bool isor = false;
    int temp = 0;

    bool headt = true;

	for (int i = 0; i < len; i++) {
        if (expr[i] == '^' /*&& (i == 0 || expr[i - 1] >= 0)*/) {
			ishead = true; headt = true;
		}
		else if (expr[i] == '$') {
			istail = true; headt = false;
		}
		else if (expr[i] == ')' /*&& (i == 0 || expr[i - 1] >= 0)*/){
			leftnum--;
			temp = 0;
			isor = false;
		}
		else if (expr[i] == '(' /*&& (i == 0 || expr[i - 1] >= 0)*/) {
			leftnum++;
			if (headt == true) temp = head_p;
			else temp = tail_p;
		}
        else if (expr[i] == '|' /*&& (i == 0 || expr[i - 1] >= 0)*/){
			

			isor = true;
		}
		else{
            if (headt == true) {
                if (isor == true) {
					head_b[temp] = expr[i];
					temp++;
				}
				else {
					head[head_p] = expr[i];
					head_p++;
				}
			}
			else {
				if (isor == true) { 
					tail_b[temp] = expr[i];
					temp++;
				}
				else {
					tail[tail_p] = expr[i];
					tail_p++;
				}
			}
		}
	}

    if (leftnum != 0) ret = -1;
}

bool reguexpr::match(string expr) {
    int expr_len = expr.size();
	int head_t = 0;
	int tail_t = 0;
	int expr_t = 0;

    if (expr_len < head_p) return false;
	while (head_t < head_p) {
        if (head[head_t] == '.') {
            if (expr[expr_t] < 0) expr_t++;
		}
		else {
            if (head[head_t] != expr[expr_t] && head_b[head_t] != expr[expr_t]) return false;
		}

		head_t++;
		expr_t++;
	}

    if (ishead == false && head_p != 0) {
		if (expr_t != expr_len) return false;
	}

	if (istail == true) {
		expr_t = expr_len - tail_p;
		if (expr_t < 0) return false;
		while (tail_t < tail_p) {
            if (tail[tail_t] == '.') {
                if (expr[expr_t] < 0) expr_t++;
			}
			else {
                if (tail[tail_t] != expr[expr_t] && tail_b[tail_t] != expr[expr_t]) return false;
			}

			tail_t++;
			expr_t++;
		}
	}

	return true;
}
