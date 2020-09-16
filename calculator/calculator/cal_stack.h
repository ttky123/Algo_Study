#define _SCL_SECURE_NO_WARNINGS
#pragma once

#include <iostream>
#include <ctype.h>  
#include <cstdlib> 
#include <stack>


using namespace std;

class Calculator {
private:
	char buffer[80];
	char postfix[80];

	stack<char> s1;
	stack<char> s2;

	void infixTopostfix();
	void result();
	int priority(char);

public:
	void calculate(char[]);
};
