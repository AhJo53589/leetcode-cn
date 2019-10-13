// 5222.split-a-string-in-balanced-strings.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
int balancedStringSplit(string s) 
{
	int l = 0;
	int ans = 0;
	for (auto c : s)
	{
		l += (c == 'L') ? 1 : -1;
		ans += (l == 0) ? 1 : 0;
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
	vector<string> TESTS;
	//vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back("RLRRLLRLRL");
	ANSWERS.push_back(4);

	TESTS.push_back("RLLLLRRRLR");
	ANSWERS.push_back(3);

	TESTS.push_back("LLLLRRRR");
	ANSWERS.push_back(1);

	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		auto ans = balancedStringSplit(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		f_time_end();
	}
}
