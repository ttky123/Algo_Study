#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector<int> vec1(9);
vector<int> vec2(9);
bool visit[9];
void dfs(int level)
{
	if (level == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << vec2[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i < n+1; i++)
	{
		if (visit[i] == false)
		{
			visit[i] = true;
			vec2[level] = i;
			dfs(level + 1);
			visit[i] = false;
		}
	}
}
int main()
{
	cin >> n >> m;

	dfs(0);
}

