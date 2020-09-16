#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>
#include  "cal_stack.h"
using namespace std;

#define MAX_SIZE 100

char operate(char *, vector<char>, vector<char>, vector<char>);
bool get_postfix(char *);
char calculate(char *, vector<char>, vector<char>, vector<char>);
char cal_at(char, char, vector<char>);
char cal_sharp(char, char, vector<char>);
char cal_et(char, char, vector<char>);

int main() {
	vector<char> output;
	char input[MAX_SIZE];
	char infile;
	vector<char> at;
	vector<char> sharp;
	vector<char> et;
	memset(input, NULL, MAX_SIZE);

	ifstream File("operations.txt");
	if (File.is_open()) {
		while (!File.eof()) {
			File >> infile;
			if (infile == '@') {
				for (int i = 0; i < 9; i++) {
					File >> infile;
					at.push_back(infile);
				}
			}
			else if (infile == '#') {
				for (int i = 0; i < 9; i++) {
					File >> infile;
					sharp.push_back(infile);
				}
			}
			else if (infile == '&') {
				for (int i = 0; i < 9; i++) {
					File >> infile;
					et.push_back(infile);
				}
			}
		}
	}
	else cout << "operations.txt 파일을 찾을 수가 없습니다." << endl;

	cout << "Input" << endl;
	while (cin >> input) {
		if (!strcmp(input, "EOI"))
			break;
		output.push_back(operate(input, at, sharp, et));
	}

	cout << endl << "Output" << endl;
	for (char n : output) {
		if (n == 'd')
			cout << "Error!" << endl;
		else
			cout << n << endl;
	}
	File.close();
	return 1;
}

char operate(char * ch, vector<char> at, vector<char> sharp, vector<char> et) {
	char output = 0;
	bool success = get_postfix(ch);
	if (success)
		output = calculate(ch, at, sharp, et);
	else
		return 'd';
	return output;
}
bool get_postfix(char* ch) {
	int j = 0;
	char result[MAX_SIZE];
	memset(result, NULL, MAX_SIZE);
	stack<char> st;

	for (int i = 0; ch[i] != NULL; i++) {
		switch (ch[i]) {
		case '{': case '[': case '(':
			st.push(ch[i]);
			break;
		case '}':
			if (!st.empty()) {
				while (!(st.top() == '{')) {
					if ((st.top() == '[') || (st.top() == '('))
						return false;
					result[j] = st.top();
					st.pop();
					j++;
				}
			}
			else
				return false;
			st.pop();
			break;
		case ']':
			if (!st.empty()) {
				while (!(st.top() == '[')) {
					if ((st.top() == '{') || (st.top() == '('))
						return false;
					result[j] = st.top();
					st.pop();
					j++;
				}
			}
			else
				return false;
			st.pop();
			break;
		case ')':
			if (!st.empty()) {
				while (!(st.top() == '(')) {
					if ((st.top() == '{') || (st.top() == '['))
						return false;
					result[j] = st.top();
					st.pop();
					j++;
				}
			}
			else
				return false;
			st.pop();
			break;
		case '@':
			if (!st.empty()) {
				if ((st.top() == '&') || (st.top() == '@') || (st.top() == '#')) {
					result[j] = st.top();
					st.pop();
					j++;
				}
			}
			st.push('@');
			break;
		case '#':
			if (!st.empty()) {
				if ((st.top() == '&') || (st.top() == '@') || (st.top() == '#')) {
					result[j] = st.top();
					st.pop();
					j++;
				}
			}
			st.push('#');
			break;
		case '&':
			if (!st.empty()) {
				if (st.top() == '&') {
					result[j] = st.top();
					st.pop();
					j++;
				}
			}
			st.push('&');
			break;
		case 'a':
			result[j] = 'a';
			j++;
			break;
		case 'b':
			result[j] = 'b';
			j++;
			break;
		case 'c':
			result[j] = 'c';
			j++;
			break;
		default:
			continue;
		}
	}
	while (!st.empty()) {
		result[j] = st.top();
		st.pop();
		j++;
	}
	strcpy_s(ch, MAX_SIZE, result);
	return true;
}
char calculate(char *ch, vector<char> at, vector<char> sharp, vector<char> et) {
	char output, oper1, oper2, res;
	stack<char> st;
	for (int i = 0; ch[i] != NULL; i++) {
		switch (ch[i]) {
		case '@':
			if (!st.empty()) {
				oper2 = st.top();
				st.pop();
			}
			if (!st.empty()) {
				oper1 = st.top();
				st.pop();
			}
			res = cal_at(oper1, oper2, at);
			st.push(res);
			break;
		case '#':
			if (!st.empty()) {
				oper2 = st.top();
				st.pop();
			}
			if (!st.empty()) {
				oper1 = st.top();
				st.pop();
			}
			res = cal_sharp(oper1, oper2, sharp);
			st.push(res);
			break;
		case '&':
			if (!st.empty()) {
				oper2 = st.top();
				st.pop();
			}
			if (!st.empty()) {
				oper1 = st.top();
				st.pop();
			}
			res = cal_et(oper1, oper2, et);
			st.push(res);
			break;
		case 'a':
			st.push('a');
			break;
		case 'b':
			st.push('b');
			break;
		case 'c':
			st.push('c');
			break;
		default:
			continue;
		}
	}
	output = st.top();
	st.pop();
	return output;
}
char cal_at(char oper1, char oper2, vector<char> at) {
	if (oper1 == 'a') {
		if (oper2 == 'a')
			return at[0];
		else if (oper2 == 'b')
			return at[1];
		else
			return at[2];
	}
	else if (oper1 == 'b') {
		if (oper2 == 'a')
			return at[3];
		else if (oper2 == 'b')
			return at[4];
		else
			return at[5];
	}
	else {
		if (oper2 == 'a')
			return at[6];
		else if (oper2 == 'b')
			return at[7];
		else
			return at[8];
	}
}
char cal_sharp(char oper1, char oper2, vector<char> sharp) {
	if (oper1 == 'a') {
		if (oper2 == 'a')
			return sharp[0];
		else if (oper2 == 'b')
			return sharp[1];
		else
			return sharp[2];
	}
	else if (oper1 == 'b') {
		if (oper2 == 'a')
			return sharp[3];
		else if (oper2 == 'b')
			return sharp[4];
		else
			return sharp[5];
	}
	else {
		if (oper2 == 'a')
			return sharp[6];
		else if (oper2 == 'b')
			return sharp[7];
		else
			return sharp[8];
	}
}
char cal_et(char oper1, char oper2, vector<char> et) {
	if (oper1 == 'a') {
		if (oper2 == 'a')
			return et[0];
		else if (oper2 == 'b')
			return et[1];
		else
			return et[2];
	}
	else if (oper1 == 'b') {
		if (oper2 == 'a')
			return et[3];
		else if (oper2 == 'b')
			return et[4];
		else
			return et[5];
	}
	else {
		if (oper2 == 'a')
			return et[6];
		else if (oper2 == 'b')
			return et[7];
		else
			return et[8];
	}
}