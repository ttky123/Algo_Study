#include "HW2_2015726030.h"

int Calculator::op_priority(char ch) { //priority between operators
	if (ch == ')')
		return 4;
	else if (ch == '&')
		return 3;
	else if (ch == '@' || ch == '#')
		return 2;
	else
		return 1;
}

bool Calculator::isOp(char ch) {//check if ch is an operand
	if ((ch == 'a') || (ch == 'b') || (ch == 'c'))
		return true;
	else
		return false;
}
void Calculator::calculate(char infix[]) { //save input notation to buf
	if (strcmp(infix, "EOI") == 0)
		exit(0);
	for (int i = 0; i < 80; i++)
		buf[i] = infix[i];
	infix_to_postfix();
	result();
}

void Calculator::infix_to_postfix() { //convert infix notation to a prefixed one
	int i = 0, j = 0;
	char ch;

	while (buf[i] != NULL) {
		if (buf[i] == ' ')
			i++;
		else if (isOp(buf[i])) { //if buf[i] is an operand, save it to postfix
			while (isOp(buf[i]))
				postfix[j++] = buf[i++];
			postfix[j++] = ' ';
		}

		else if (buf[i] == '(') { //push left parenthesis into stack
			s2.push(buf[i]);
			i++;
		}
		else if (buf[i] == ')') { //pop operands till reaching the left parenthesis
			if (!s2.empty())
				ch = s2.top(); s2.pop();
			while ((ch != '(') || (ch != '{') || (ch != '[')) {
				if (s2.empty()) {
					cout << "result = " << "ERROR" << endl;
					exit(0);
				}
				postfix[j++] = ch;
				postfix[j++] = ' ';
				ch = s2.top(); s2.pop();

			}
			i++;
		}

		else if (buf[i] == '{') {
			s2.push(buf[i]);
			i++;
		}
		else if (buf[i] == '}') {
			if (!s2.empty())
				ch = s2.top(); s2.pop();
			while ((ch != '(') || (ch != '{') || (ch != '[')) {
				if (s2.empty()) {
					cout << "result = " << "ERROR" << endl;
					exit(0);
				}
				postfix[j++] = ch;
				postfix[j++] = ' ';
				ch = s2.top(); s2.pop();
			}
			i++;
		}
		else if (buf[i] == '[') {
			s2.push(buf[i]);
			i++;
		}
		else if (buf[i] == ']') {
			if (!s2.empty())
				ch = s2.top(); s2.pop();
			while ((ch != '(') || (ch != '{') || (ch != '[')) {
				if (s2.empty()) {
					cout << "result = " << "ERROR" << endl;
					exit(0);
				}
				postfix[j++] = ch;
				postfix[j++] = ' ';
				ch = s2.top(); s2.pop();
			}
			i++;
		}
		else {
			if (s2.empty())
				s2.push(buf[i++]);
			else {
				while (!s2.empty() && op_priority(s2.top()) >= op_priority(buf[i])) {
					ch = s2.top(); s2.pop();
					postfix[j++] = ch;
					postfix[j++] = ' ';
				}
				s2.push(buf[i]);
				i++;
			}
		}
	}
	while (!s2.empty()) { //if notation ended, pop stack
		ch = s2.top(); s2.pop();
		postfix[j++] = ch;
		postfix[j++] = ' ';
	}
	postfix[j] = NULL;


	cout << "postfix : " << postfix << endl;
}

void Calculator::result() {
	int i = 0, k, j;
	char buf[5];
	char result, num1, num2;
	char ch;
	string opr;
	string str;
	str = "";
	ifstream is;
	is.open("operations.txt");
	while (!is.eof()) {
		is >> str;
		opr.append(str);
	}

	while (postfix[i] != NULL) {
		if (isOp(postfix[i])) {
			k = 0;
			while (isOp(postfix[i])) {
				buf[k] = postfix[i++];
				s1.push(buf[k++]);
			}

			//         token[k] = NULL;
		}
		else if (postfix[i] == ' ')
			i++;
		else if ((postfix[i] == '(') || (postfix[i] == '{') || (postfix[i] == '[')) {
			cout << "result = " << "ERROR" << endl;
			return;
		}
		else { //if a operator was met, pop out two opernads and calculate
			j = 0;
			ch = postfix[i++];
			num1 = s1.top(); s1.pop();
			num2 = s1.top(); s1.pop();
			if (ch == '@') {
				j = 0;
				switch (num2) {
				case 'a':
					switch (num1) {
					case'a':result = opr[1]; break;
					case'b':result = opr[2]; break;
					case'c':result = opr[3]; break;
					}
					break;
				case 'b':
					switch (num1) {
					case'a':result = opr[4]; break;
					case'b':result = opr[5]; break;
					case'c':result = opr[6]; break;
					}
					break;
				case 'c':
					switch (num1) {
					case'a':result = opr[7]; break;
					case'b':result = opr[8]; break;
					case'c':result = opr[9]; break;
					}
					break;
				}
			}
			else if (ch == '&') {
				switch (num2) {
				case 'a':
					switch (num1) {
					case'a':result = opr[21]; break;
					case'b':result = opr[22]; break;
					case'c':result = opr[23]; break;
					}
					break;
				case 'b':
					switch (num1) {
					case'a':result = opr[24]; break;
					case'b':result = opr[25]; break;
					case'c':result = opr[26]; break;
					}
					break;
				case 'c':
					switch (num1) {
					case'a':result = opr[27]; break;
					case'b':result = opr[28]; break;
					case'c':result = opr[29]; break;
					}
					break;
				}
			}
			else if (ch == '#') {
				switch (num2) {
				case 'a':
					switch (num1) {
					case'a':result = opr[11]; break;
					case'b':result = opr[12]; break;
					case'c':result = opr[13]; break;
					}
					break;
				case 'b':
					switch (num1) {
					case'a':result = opr[14]; break;
					case'b':result = opr[15]; break;
					case'c':result = opr[16]; break;
					}
					break;
				case 'c':
					switch (num1) {
					case'a':result = opr[17]; break;
					case'b':result = opr[18]; break;
					case'c':result = opr[19]; break;
					}
					break;
				}
			}
			s1.push(result);
		}
		i++;

	}
	cout << "result = " << s1.top() << endl;
	s1.pop();
}