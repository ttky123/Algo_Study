// B_2748.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;
int arr[90];
int n;

unsigned long long fibo[100];

unsigned long long Get_Fibo(int n) {
	if (n <= 1) return fibo[n];
	if (fibo[n] != -1)return fibo[n];
	fibo[n] = Get_Fibo(n - 1) + Get_Fibo(n - 2);
	return fibo[n];
}




int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		arr[i] = -1;
	}
	arr[0] = 0, arr[1] = 1;
	cout << Get_Fibo(n);

}

