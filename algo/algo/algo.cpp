#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 10;
int size, cnt;
int moveCount = 1;
vector<int> myvec;
void save(int x) {
	moveCount++;
	myvec.push_back(x);
}
int main() 
{
		int size,cnt = 1;
		string str;
		while (str.compare("EOI") != true) {
			cnt = 1;
			moveCount = 1;
			myvec.clear();
			cin >> str;
			if (str.compare("EOI") == 0) {
				return 0;
			}
			size = stoi(str);
			int left = size, blank = 1;

			save(left);
			for (int i = 1; i < size; ++i) {	//move black stone to right
				for (int j = 0; j < i; ++j) {
					save(left += 2 * blank);
				}
				save(left += blank);

				blank = -blank;
			}
			for (int i = 0; i < size; ++i) {	//save position of blank hole
				save(left += 2 * blank);
			}
			blank = -blank;
			for (int i = size - 1; i > 0; --i) {	//move white stone to left
				save(left += blank);
				for (int j = 0; j < i; ++j) {
					save(left += 2 * blank);
				}
				blank = -blank;
			}
			cout << moveCount << endl;
			for (vector<int>::const_iterator it = myvec.cbegin(); it != myvec.cend(); ++it) {
				cout << *it << " ";
				if (cnt++ % 20 == 0)
					cout << endl;
			}
			cout << --left << endl;
		}
	return 0;
}