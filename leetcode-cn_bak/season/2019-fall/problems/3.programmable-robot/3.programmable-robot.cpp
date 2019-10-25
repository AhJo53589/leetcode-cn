// 3.programmable-robot.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
//	int a = 0, b = 0, u = 0, v = 0;
//	for (auto i : command)if (i == 'R')a++;
//	else b++;
//	bool c = 0;
//	for (auto i : command)
//	{
//		for (auto j : obstacles)if (j[0] <= x && j[1] <= y && (j[0] - u) % a == 0 && (j[1] - v) % b == 0 && (j[0] - u) / a == (j[1] - v) / b)return 0;
//		if ((x - u) % a == 0 && (y - v) % b == 0 && (x - u) / a == (y - v) / b)c = 1;
//		if (i == 'R')u++;
//		else v++;
//	}
//	return c;
//}

//////////////////////////////////////////////////////////////////////////
//bool robot(string command, vector<vector<int>>& obstacles, int x, int y) 
//{
//	int a = 0, b = 0, u = 0, v = 0;
//	for (auto i : command)
//	{
//		if (i == 'R')
//			a++;
//		else 
//			b++;
//	}
//
//	bool c = false;
//	for (auto i : command)
//	{
//		for (auto j : obstacles)
//		{
//			if (j[0] <= x && j[1] <= y
//				&& (j[0] - u) % a == 0
//				&& (j[1] - v) % b == 0
//				&& (j[0] - u) / a == (j[1] - v) / b)
//			{
//				return false;
//			}
//		}
//		if ((x - u) % a == 0
//			&& (y - v) % b == 0
//			&& (x - u) / a == (y - v) / b)
//		{
//			c = true;
//		}
//
//		if (i == 'R')
//		{
//			u++;
//		}
//		else
//		{
//			v++;
//		}
//	}
//	return c;
//}

//////////////////////////////////////////////////////////////////////////
bool robot(string command, vector<vector<int>>& obstacles, int x, int y)
{
	vector<vector<int>> ob2(obstacles.begin(), obstacles.end());
	sort(obstacles.begin(), obstacles.end(), [](const vector<int>& a, const vector<int>& b)
	{
		return a[0] < b[0];
	});
	sort(ob2.begin(), ob2.end(), [](const vector<int>& a, const vector<int>& b)
	{
		return a[1] < b[1];
	});

	size_t i_x = 0;
	size_t i_y = 0;

	vector<int> pos(2, 0);
	while (true)
	{
		for (auto &c : command)
		{
			if (pos[0] == x && pos[1] == y) return true;
			if (pos[0] > x || pos[1] > y) return false;

			if (c == 'R')
			{
				pos[0]++;
				if (obstacles.size() == 0) continue;
				while (i_x < obstacles.size() && obstacles[i_x][0] < pos[0]) i_x++;
				while (i_x < obstacles.size() && obstacles[i_x][0] == pos[0])
				{
					if (obstacles[i_x][1] == pos[1]) return false;
					i_x++;
				}
			}
			else if (c == 'U')
			{
				pos[1]++;
				if (ob2.size() == 0) continue;
				while (i_y < ob2.size() && ob2[i_y][1] < pos[1]) i_y++;
				while (i_y < ob2.size() && ob2[i_y][1] == pos[1])
				{
					if (ob2[i_y][0] == pos[0]) return false;
					i_y++;
				}
			}
		}
	}
	return false;
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
	vector<string> C;
	vector<int> X;
	vector<int> Y;
	vector<bool> ANSWERS;

	TESTS.push_back({  });
	C.push_back("URR");
	X.push_back(3);
	Y.push_back(2);
	ANSWERS.push_back(true);

	TESTS.push_back({ {2,2} });
	C.push_back("URR");
	X.push_back(3);
	Y.push_back(2);
	ANSWERS.push_back(false);

	TESTS.push_back({ {4,2} });
	C.push_back("URR");
	X.push_back(3);
	Y.push_back(2);
	ANSWERS.push_back(true);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = robot(C[i], TESTS[i], X[i], Y[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}