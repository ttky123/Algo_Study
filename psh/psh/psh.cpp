
#include <iostream>
#include <string>
#include <unordered_map>
#include <time.h>

using namespace std;

int main()
{
	int num;
	string words;
	unordered_map<string, int> message;
	cin >> num >> words;
	clock_t start = clock();
	pair<string, int> result("", 0);   //pair객체 생성.
	for (int i = 0; i < words.size() - num + 1; ++i) {
		string comp_word; //선언 위치가 바뀌면 시발 값이 달라짐. 이유는?
		for (int j = 0; j < num; ++j) {
			comp_word += words[i + j];
		}
		if (message.find(comp_word) == message.end()) {
			message[comp_word] = 1; //아니면 안 증가.
		}
		else {
			message[comp_word] += 1; //더 있는 key값 증가.
			result.first = comp_word;
			result.second = message[comp_word];
		}
	}
	clock_t end = clock();
	int res_t = (int)(end - start);
	cout << result.first << ' ' << result.second << endl;
	cout << (res_t / 1000) << "ms";
	return 0;
}