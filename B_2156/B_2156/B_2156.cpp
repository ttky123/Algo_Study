#include "pch.h"
#include <iostream>
#include <algorithm>
int n;
using namespace std;
int main()
{
	cin >> n;
	int arr[10003]{ 0, };
	int dp[10003] = { 0, };
	int result=0;
	for (int i = 3; i < n+3; i++)
	{
		cin >> arr[i];
	}
	for (int i = 3; i < n+3; i++)
	{
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		dp[i] = max(dp[i - 1], dp[i]);
		result = max(result, dp[i]);
	}

	cout << result << '\n';
}

