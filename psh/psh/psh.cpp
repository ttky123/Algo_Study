
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
	pair<string, int> result("", 0);   //pair��ü ����.
	for (int i = 0; i < words.size() - num + 1; ++i) {
		string comp_word; //���� ��ġ�� �ٲ�� �ù� ���� �޶���. ������?
		for (int j = 0; j < num; ++j) {
			comp_word += words[i + j];
		}
		if (message.find(comp_word) == message.end()) {
			message[comp_word] = 1; //�ƴϸ� �� ����.
		}
		else {
			message[comp_word] += 1; //�� �ִ� key�� ����.
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