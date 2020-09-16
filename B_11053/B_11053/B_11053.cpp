#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
int arr[1000];
int n;
int result;
int dp[1000];
using namespace std;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
		result = max(result, dp[i]);

	cout << result<<'\n';


}

