// 5088.missing-number-in-arithmetic-progression.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//int missingNumber(vector<int>& arr) 
//{
//	// 数组求和
//	int sum = accumulate(arr.begin(), arr.end(), 0);
//	// 公式求和 - 数组求和
//	return (arr.size() + 1) * (arr.front() + arr.back()) / 2 - sum;
//}


//////////////////////////////////////////////////////////////////////////
int missingNumber(vector<int>& arr)
{
	if (arr.back() < arr.front())
	{
		reverse(arr.begin(), arr.end());
	}
	int k = arr[1] - arr[0];
	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i + 1] - arr[i] == k) continue;
		if (arr[i + 1] - arr[i] > k) return arr[i] + k;
		break;
	}
	return arr[0] + k / 2;
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
	vector<int> ANSWERS;

	TESTS.push_back({ 5,7,11,13 });
	ANSWERS.push_back(9);

	TESTS.push_back({ 15,13,12 });
	ANSWERS.push_back(14);

	TESTS.push_back({ 100,300,400 });
	ANSWERS.push_back(200);

	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		auto ans = missingNumber(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		f_time_end();
	}
}