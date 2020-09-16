#include "HW2_2015726030.h"
using namespace std;

int main() {
	char str[80];
	Calculator cal = Calculator();
	while (true) {
		cout << "INPUT(INPUT EOI TO EXIT): ";
		cin >> str;
		cal.calculate(str);
		cout << endl;
	}
}