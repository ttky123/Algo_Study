#include "cal_stack.h"
#include <vector>
using namespace std;

int main() {
	Calculator cal = Calculator();
	char str[30];
	while (true) {
		cout << "INPUT: ";
		cin >> str;
		cal.calculate(str);
	}
}