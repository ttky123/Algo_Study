#pragma once
#include<stack>
#include <iostream>
#include <ctype.h>  
#include <stdlib.h> 
#include <string>
#include <fstream>
using namespace std;

class Calculator {
private:
	char buf[80];
	char postfix[80];
	stack<char> s1;
	stack<char> s2;

	void infix_to_postfix();
	void result();
	int op_priority(char ch);
	bool isOp(char ch);
public:
	void calculate(char[]);
};

