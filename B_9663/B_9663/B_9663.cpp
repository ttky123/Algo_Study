#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 15;

int n;
int chess[15];
int qcount;
using namespace std;
bool check(int row)
{
	for (int i = 0; i < row; i++)
	{
		if (chess[i] == chess[row])
			return false;
		if (abs(chess[i] - chess[row]) == abs(i - row))
			return false;
	}

	return true;
}
void wtf(int level)
{
	if (level == n)
	{
		qcount++;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			chess[level] = i;
			if (check(level))
			{
				wtf(level + 1);
			}
		}
	}
}

int main()
{
	qcount = 0;
	cin >> n;
	wtf(0);
	cout << qcount << '\n';
}
