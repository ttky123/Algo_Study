#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> vec1(9);
vector<int> vec2(9);
bool visit[9][9];
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
	for (int i = 1; i < n + 1; i++)
	{
		if (visit[i][level] == false)
		{
			visit[i][level] = true;
			vec2[level] = i;
			dfs(level + 1);
			visit[i][level] = false;
		}
	}
}
int main()
{
	cin >> n >> m;

	dfs(0);
}

