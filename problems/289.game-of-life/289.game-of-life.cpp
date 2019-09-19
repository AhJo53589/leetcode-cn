// 289.game-of-life.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//#include "..\Common\GraphNode.Hi"
//#include "..\Common\TreeNode.Hi"
//#include "..\Common\ListNode.Hi"
using namespace std;


//////////////////////////////////////////////////////////////////////////
void gameOfLife(vector<vector<int>>& board)
{
	size_t m = board.size();
	if (m == 0) return;
	size_t n = board[0].size();

	auto getNear = [m, n](size_t _i, size_t _j, vector<vector<size_t>> &pos)
	{
		for (size_t i = max((size_t)1, _i) - 1; i < min(m, _i + 2); i++)
		{
			for (size_t j = max((size_t)1, _j) - 1; j < min(n, _j + 2); j++)
			{
				if (i == _i && j == _j) continue;
				pos.push_back({ i, j });
			}
		}
	};

	for (size_t i = 0; i < board.size(); i++)
	{
		for (size_t j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] > 0)
			{
				vector<vector<size_t>> pos;
				getNear(i, j, pos);
				for (auto &p : pos)
				{
					int &x = board[p[0]][p[1]];
					x = (x > 0) ? x + 1 : x - 1;
				}
			}
		}
	}

	for (size_t i = 0; i < board.size(); i++)
	{
		for (size_t j = 0; j < board[i].size(); j++)
		{
			int &x = board[i][j];
			if (x > 0)
			{
				x = (x == 2 + 1 || x == 3 + 1) ? 1 : 0;
			}
			else
			{
				x = (x == -3) ? 1 : 0;
			}
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
	vector<vector<vector<int>>> TESTS;
	//vector<vector<int>> K;
	vector<vector<vector<int>>> ANSWERS;

	TESTS.push_back({ {0,1,0},{0,0,1},{1,1,1},{0,0,0} });
	//K.push_back({ 1,1 });
	ANSWERS.push_back({ {0,0,0},{1,0,1},{0,1,1},{0,1,0} });

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		//auto ans = gameOfLife(TESTS[i], K[i]);
		//cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
		gameOfLife(TESTS[i]);
		cout << checkAnswer<vector<vector<int>>>(TESTS[i], ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}