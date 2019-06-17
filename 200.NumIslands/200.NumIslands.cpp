// 200.NumIslands.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <random>

using namespace std;


void checkIsland(vector<vector<char>>& grid, pair<int, int> posStart)
{
	queue<pair<int, int>> q;
	q.push(posStart);

	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();

		if (p.first >= 0 && p.first < grid.size() && p.second >= 0 && p.second < grid[0].size())
		{
			if (grid[p.first][p.second] == '1')
			{
				grid[p.first][p.second] = '2';

				q.push(make_pair(p.first, p.second - 1));
				q.push(make_pair(p.first, p.second + 1));
				q.push(make_pair(p.first - 1, p.second));
				q.push(make_pair(p.first + 1, p.second));
			}
		}
	}
}

int numIslands(vector<vector<char>>& grid)
{
	int iLen_i = grid.size();
	if (iLen_i == 0) return 0;
	int iLen_j = grid[0].size();
	if (iLen_j == 0) return 0;

	int num = 0;
	for (int i = 0; i < iLen_i; i++)
	{
		for (int j = 0; j < iLen_j; j++)
		{
			if (grid[i][j] == '1')
			{
				checkIsland(grid, make_pair(i, j));
				num++;
			}
		}
	}

	return num;
}

void initVectorChar(vector<vector<char>>& grid)
{
	vector<string> vStr;
	string str;
	str.clear();
	str.append("11110");
	vStr.push_back(str);
	str.clear();
	str.append("11010");
	vStr.push_back(str);
	str.clear();
	str.append("11000");
	vStr.push_back(str);
	str.clear();
	str.append("00000");
	vStr.push_back(str);

	//str.clear();
	//str.append("11000");
	//vStr.push_back(str);
	//str.clear();
	//str.append("11000");
	//vStr.push_back(str);
	//str.clear();
	//str.append("00100");
	//vStr.push_back(str);
	//str.clear();
	//str.append("00011");
	//vStr.push_back(str);

	for (string s : vStr)
	{
		vector<char> vChar;
		for (int i = 0; i < s.size(); i++)
		{
			vChar.push_back(s[i]);
		}
		grid.push_back(vChar);
	}
}

int main()
{
	vector<vector<char>> grid;
	initVectorChar(grid);

	cout << numIslands(grid);
}
