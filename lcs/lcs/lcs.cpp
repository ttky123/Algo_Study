//2015726015 ¿Ã√Êº∑
#include <iostream>
#include <string>
#include <conio.h>
#include <unordered_map>
#include <time.h>


using namespace std;

int main() {
	int num = 8;
	string str;

	cin >> num >> str;

	clock_t start = clock();
	unordered_map<string, int> strBox;

	//cout << str.size() << endl;
	strBox.reserve(str.size() / 2);
	cout << "count: " << strBox.bucket_count() << endl;

	int max = 0;
	string result;
	string key;
	auto itr = strBox.begin();
	for (int i = 0; str[i + num] != NULL; i++) {
		itr = strBox.find(str.substr(i, num));
		if (itr == strBox.end())
			strBox[str.substr(i, num)] = 1;
		else {
			itr->second++;

			if (itr->second > max) {
				max = itr->second;
				result = itr->first;
			}
		}
	}
	cout << "count: " << strBox.bucket_count() << endl;
	cout << "√— " << max << "π¯ ≥™ø¬ " << result << endl;
	clock_t end = clock();
	cout << "Ω√∞£: " << double(end - start) / 1000.0 << endl;
	return 0;
}