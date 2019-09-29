// 5205.unique-number-of-occurrences.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
bool uniqueOccurrences(vector<int>& arr)
{
	map<int, int> m;
	for (auto n : arr)
	{
		m[n]++;
	}
	unordered_set<int> s;
	for (auto k : m)
	{
		if (s.find(k.second) != s.end()) return false;
		s.insert(k.second);
	}
	return true;
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
	vector<vector<int>> TESTS;
	//vector<int> K;
	vector<bool> ANSWERS;

	TESTS.push_back({ 1,2,2,1,1,3 });
	ANSWERS.push_back(true);

	TESTS.push_back({ 1,2 });
	ANSWERS.push_back(false);

	TESTS.push_back({ -3,0,1,-3,1,1,1,-3,10,0 });
	ANSWERS.push_back(true);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = uniqueOccurrences(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}