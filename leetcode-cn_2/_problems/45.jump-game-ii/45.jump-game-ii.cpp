﻿// 45.jump-game-ii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
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

#include "..\Common\ParameterType.h"
#include "..\Common\Common.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//int jump(vector<int> &nums)
int jump(vector<int> nums)
{
	int ans = 0;
	int begin = 0;
	int end = 1;
	while (end < nums.size())
	{
		int temp = 0;
		for (int i = begin; i < end; i++)
		{
			temp = max(temp, i + nums[i]);
		}
		begin = end;
		end = temp + 1;
		ans++;
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
//int jump(vector<int> &nums)
//int jump(vector<int> nums)
//{
//	int ans = 0;
//	int end = 0;
//	int maxPos = 0;
//	for (int i = 0; i < nums.size() - 1; i++)
//	{
//		maxPos = max(nums[i] + i, maxPos);
//		if (i == end)
//		{
//			end = maxPos;
//			ans++;
//		}
//	}
//	return ans;
//}


#define TEST_FUNC jump
int main()
{
	PerformanceTimer timer;
	ifstream f("tests.txt");
	TestCases test_cases(f);

	using func_t = function_type<function<decltype(TEST_FUNC)>>;
	while (!test_cases.empty())
	{
		timer.start();

		func_t::return_type ans = func_t::call(TEST_FUNC, test_cases);
		func_t::return_type answer = test_cases.get<func_t::return_type>();
		cout << checkAnswer<decltype(ans)>(ans, answer) << endl;

		timer.stop();
	}
}
