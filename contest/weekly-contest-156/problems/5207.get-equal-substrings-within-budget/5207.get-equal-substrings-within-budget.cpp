// 5207.get-equal-substrings-within-budget.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
int equalSubstring(string s, string t, int maxCost)
{
	auto f_cost = [s, t](size_t i)
	{
		return abs(s[i] - t[i]);
	};

	size_t start = 0;
	int c = 0;
	int ans = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		c += f_cost(i);
		while (c > maxCost)
		{
			c -= f_cost(start++);
		}
		ans = max(ans, (int)(i - start) + 1);
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
	vector<string> TESTS;
	vector<string> T;
	vector<int> M;
	vector<int> ANSWERS;

	TESTS.push_back("abcd");
	T.push_back("bcdf");
	M.push_back(3);
	ANSWERS.push_back(3);

	TESTS.push_back("abcd");
	T.push_back("cdef");
	M.push_back(3);
	ANSWERS.push_back(1);

	TESTS.push_back("abcd");
	T.push_back("acde");
	M.push_back(0);
	ANSWERS.push_back(1);

	TESTS.push_back("krrgw");
	T.push_back("zjxss");
	M.push_back(19);
	ANSWERS.push_back(2);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = equalSubstring(TESTS[i], T[i], M[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}