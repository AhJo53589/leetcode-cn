// 5223.queens-that-can-attack-the-king.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <functional>

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
//void calc(vector<int> &king, vector<int> &queen, vector<vector<int>> &ans)
//{
//	int kx = king[0];
//	int ky = king[1];
//	int qx = queen[0];
//	int qy = queen[1];
//
//	int i = 0;
//	if (kx == qx)
//	{
//		if (ky < qy) i = 0;
//		else i = 4;
//		if (ans[i].empty())
//		{
//			ans[i].push_back(qx);
//			ans[i].push_back(qy);
//		}
//		else if (abs(qy - ky) < abs(ans[i][1] - ky))
//		{
//			ans[i][1] = qy;
//		}
//	}
//	else if (ky == qy)
//	{
//		i = (kx < qx) ? 2 : 6;
//		if (ans[i].empty())
//		{
//			ans[i].push_back(qx);
//			ans[i].push_back(qy);
//		}
//		else if (abs(qx - kx) < abs(ans[i][0] - kx))
//		{
//			ans[i][0] = qx;
//		}
//	}
//	else if (abs(qy - ky) == abs(qx - kx))
//	{
//		if (qy - ky == qx - kx)
//		{
//			i = (ky < qy) ? 1 : 5;
//		}
//		else
//		{
//			i = (kx < qx) ? 3 : 7;
//		}
//		if (ans[i].empty())
//		{
//			ans[i].push_back(qx);
//			ans[i].push_back(qy);
//		}
//		else if (abs(qx - kx) < abs(ans[i][0] - kx))
//		{
//			ans[i][0] = qx;
//			ans[i][1] = qy;
//		}
//	}
//}
//vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king)
//{
//	vector<vector<int>> temp(8, vector<int>());
//	for (auto v : queens)
//	{
//		calc(king, v, temp);
//	}
//	vector<vector<int>> ans;
//	for (auto v : temp)
//	{
//		if (v.empty()) continue;
//		ans.push_back(v);
//	}
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) 
{
	vector<vector<bool>> board(8, vector<bool>());
	for (auto &b : board)
	{
		b.resize(8);
	}
	for (const auto &q : queens)
	{
		board[q[0]][q[1]] = true;
	}

	vector<int> dx = {1, 1, 1, 0,-1,-1,-1, 0};
	vector<int> dy = {1, 0,-1,-1,-1, 0, 1, 1};

	vector<vector<int>> ans;
	for (size_t i = 0; i != dx.size(); i++)
	{
		int x = king[0];
		int y = king[1];
		while (x >= 0 && x < 8 && y >= 0 && y < 8)
		{
			if (board[x][y])
			{
				ans.push_back({ x,y });
				break;
			}
			x += dx[i];
			y += dy[i];
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

	auto f_time_begin = [&time, &nFreq, &nBeginTime, &nEndTime]()
	{
		cout << endl << "/////////////////////////////" << endl;
		QueryPerformanceCounter(&nBeginTime);
	};

	auto f_time_end = [&time, &nFreq, &nBeginTime, &nEndTime]()
	{
		QueryPerformanceCounter(&nEndTime);
		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		cout << "////////////////////////////////////////////////////////// time: " << time * 1000 << "ms" << endl;
	};

	//////////////////////////////////////////////////////////////////////////
	vector<vector<vector<int>>> TESTS;
	vector<vector<int>> K;
	vector<vector<vector<int>>> ANSWERS;

	TESTS.push_back({ {0,1},{1,0},{4,0},{0,4},{3,3},{2,4} });
	K.push_back({ 0,0 });
	ANSWERS.push_back({ {0,1},{1,0},{3,3} });

	TESTS.push_back({ {0,0},{1,1},{2,2},{3,4},{3,5},{4,4},{4,5} });
	K.push_back({ 3,3 });
	ANSWERS.push_back({ {2,2},{3,4},{4,4} });

	TESTS.push_back({ {5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7} });
	K.push_back({ 3,4 });
	ANSWERS.push_back({ {2,3},{1,4},{1,6},{3,7},{4,3},{5,4},{4,5} });

	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		auto ans = queensAttacktheKing(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		f_time_end();
	}
}
