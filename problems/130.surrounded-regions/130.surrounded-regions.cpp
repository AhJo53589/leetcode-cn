// 130.surrounded-regions.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
using namespace std;


//////////////////////////////////////////////////////////////////////////
void dfs(vector<vector<char>>& board, size_t x, size_t y)
{
	if (x >= board.size() || y >= board[x].size() || board[x][y] != 'O') return;
	board[x][y] = '-';
	dfs(board, x - 1, y);
	dfs(board, x + 1, y);
	dfs(board, x, y - 1);
	dfs(board, x, y + 1);
}

void solve(vector<vector<char>>& board)
{
	size_t m = board.size();
	if (m == 0) return;
	size_t n = board[0].size();

	for (size_t i = 0; i < m; i++)
	{
		dfs(board, i, 0);
		dfs(board, i, n - 1);
	}
	for (size_t j = 0; j < n; j++)
	{
		dfs(board, 0, j);
		dfs(board, m - 1, j);
	}

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			board[i][j] = (board[i][j] != '-') ? 'X' : 'O';
		}
	}
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
	vector<vector<vector<char>>> TESTS;
	vector<vector<vector<char>>> ANSWERS;

	TESTS.push_back({ {'X','X','X','X'}, {'X','O','O','X'}, {'X','X','O','X'}, {'X','O','X','X'} });
	ANSWERS.push_back({ {'X','X','X','X'}, {'X','X','X','X'}, {'X','X','X','X'}, {'X','O','X','X'} });


	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		solve(TESTS[i]);
		cout << checkAnswer<vector<vector<char>>>(TESTS[i], ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}