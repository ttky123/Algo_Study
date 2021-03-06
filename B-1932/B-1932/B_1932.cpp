
#include "pch.h"
#include <iostream>
#include <algorithm>

int n;
int dp[500][500];

using namespace std;
int main()
{
	int result = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> dp[i][j];
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][0] + dp[i][j];
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1])+dp[i][j];

			result = max(result, dp[i][j]);
		}
	}

	cout << result << '\n';
}
