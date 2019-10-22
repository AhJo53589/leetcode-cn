// 695.max-area-of-island.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>

#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <bitset>
#include <sstream>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
void dfs(vector<vector<int>> &grid, int i, int j, int &ans)
{
	int m = grid.size();
	if (m == 0) return;
	int n = grid[0].size();
	if (n == 0) return;
	if (i >= m || i < 0) return;
	if (j >= n || j < 0) return;
	if (grid[i][j] == 0) return;

	ans++;
	grid[i][j] = 0;
	dfs(grid, i - 1, j, ans);
	dfs(grid, i + 1, j, ans);
	dfs(grid, i, j - 1, ans);
	dfs(grid, i, j + 1, ans);
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
	int ans = 0;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			int temp = 0;
			dfs(grid, i, j, temp);
			ans = max(ans, temp);
		}
	}
	return ans;
}


int main()
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);

	auto f_time_cout = [&]()
	{
		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		cout << "////////////////////////////////////////////////////////// time: " << time * 1000 << "ms" << endl;
	};

	//////////////////////////////////////////////////////////////////////////
	vector<vector<vector<int>>> TESTS;
	//vector<string> K;
	vector<int> ANSWERS;

	TESTS.push_back(StringToVectorVectorInt("[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]"));
	ANSWERS.push_back(6);

	TESTS.push_back(StringToVectorVectorInt("[[0,0,0,0,0,0,0,0]]"));
	ANSWERS.push_back(0);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = maxAreaOfIsland(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}