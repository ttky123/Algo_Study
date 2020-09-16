//2015726030 ¹ÚÀç¿ø
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1
#include <iostream>
#include <string>
#include <unordered_map>
#include <time.h>
using namespace std;
using namespace stdext;
#define CAPACITY 52430003
/*int hash_func(string s) {
	int index = 0;
	for (int i = 0; i < s.length(); i++) {
		index += 33 * index + s[i];
	}
	return (index % CAPACITY);
}*/
int main(void) {
	int num;
	//receiving input via redirection
	cin >> num;
	string str1, str2,str3;
	cin >> str1;
	
	unordered_map<string, int> _map;      //map to store the input 
	unordered_map<string, int>::iterator iter;   //iterator to use for loop
	//pair<string, int> result;
	_map.reserve(str1.length() * 12);
	string result = "";
	int max = 0;
	clock_t start = clock();
	for (int i = 0; i < str1.length() - num + 1; i++) {   //number of possible substring = str1.length - n + 1
		str2.clear();
		str2 += str1.substr(i, num);               //store substring into str2
		_map[str2]++;
		if (_map[str2] > max)
		{
			result = str2;
			max = _map[str2];
		}
	}

	/*   for (iter = _map.begin(); iter != _map.end(); iter++) {   //compare all values, find the max
		  if (result.second < iter->second) {
			 result.first = iter->first; result.second = iter->second;
		  }
	   }*/
	   //cout << result.first << " with " << result.second << " of frequency!\n";
	cout << result << " with " << max << " of frequency!\n";
	clock_t end = clock();
	int res = (int)(end - start);
	cout << res << " ms\n";
}