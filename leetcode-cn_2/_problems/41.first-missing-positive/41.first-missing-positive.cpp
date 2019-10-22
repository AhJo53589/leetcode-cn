// 41.first-missing-positive.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
int firstMissingPositive(vector<int>& nums)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] >= 1 && nums[i] < nums.size())
		{
			int t = nums[i] - 1;
			if (nums[i] != nums[t])
			{
				swap(nums[i], nums[t]);
				i -= (t > i);
			}
		}
	}
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] != i + 1) return i + 1;
	}
	return nums.size() + 1;
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
	vector<int> ANSWERS;

	TESTS.push_back({ 1,2,0 });
	ANSWERS.push_back(3);

	TESTS.push_back({ 3,4,-1,1 });
	ANSWERS.push_back(2);

	TESTS.push_back({ 7,8,9,11,12 });
	ANSWERS.push_back(1);

	TESTS.push_back({  });
	ANSWERS.push_back(1);

	TESTS.push_back({ 1 });
	ANSWERS.push_back(2);

	TESTS.push_back({ -1,4,2,1,9,10 });
	ANSWERS.push_back(3);

	TESTS.push_back({ 2,2,2,2,2 });
	ANSWERS.push_back(1);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;

		auto ans = firstMissingPositive(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}