// 5111.divide-chocolate.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <functional>

#include <algorithm>
#include <numeric>
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
bool calc(vector<int> &vec, int k, int d)
{
	int val = 0;
	int cnt = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		val += vec[i];
		if (val >= d && cnt < k)
		{
			val = 0;
			cnt++;
		}
	}
	return val >= d;
}

int maximizeSweetness(vector<int>& sweetness, int K) 
{
	int lb = 0, ub = 1e10;
	while (ub - lb > 1)
	{
		int mid = lb + (ub - lb) / 2;
		if (calc(sweetness, K, mid)) lb = mid;
		else ub = mid;
	}
	return lb;
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
	vector<vector<int>> TESTS;
	vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back(StringToVectorInt("[1,2,3,4,5,6,7,8,9]"));
	K.push_back(5);
	ANSWERS.push_back(6);

	TESTS.push_back(StringToVectorInt("[5,6,7,8,9,1,2,3,4]"));
	K.push_back(8);
	ANSWERS.push_back(1);

	TESTS.push_back(StringToVectorInt("[1,2,2,1,2,2,1,2,2]"));
	K.push_back(2);
	ANSWERS.push_back(5);

	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		auto ans = maximizeSweetness(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		f_time_end();
	}
}