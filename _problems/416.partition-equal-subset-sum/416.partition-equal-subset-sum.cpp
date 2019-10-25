// 416.partition-equal-subset-sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
bool DFS(const vector<int>& nums, int start, int curSum, int C)
{
	curSum += nums[start];
	if (curSum == C) return true;

	for (int i = start - 1; i >= 0; --i)
	{
		if (curSum + nums[i] > C) continue;
		return DFS(nums, i, curSum, C);
	}
	return false;
}

bool canPartition(vector<int>& nums)
{
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
	}
	if (sum % 2 != 0) return false;

	sort(nums.begin(), nums.end());
	int C = sum / 2;
	if (nums.back() > C) return false;

	for (int i = nums.size() - 1; i >= 0; --i)
	{
		if (DFS(nums, i, 0, C)) return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////



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

	TESTS.push_back({ 21, 1, 1, 1 });
	ANSWERS.push_back(false);

	TESTS.push_back({ 1, 5, 11, 5 });
	ANSWERS.push_back(true);

	TESTS.push_back({ 1, 5, 10, 6 });
	ANSWERS.push_back(true);

	TESTS.push_back({ 3, 4, 5, 7, 11 });
	ANSWERS.push_back(true);

	TESTS.push_back({ 3, 4, 5, 7, 13 });
	ANSWERS.push_back(true);

	TESTS.push_back({ 3, 4, 5, 12, 12 });
	ANSWERS.push_back(false);

	TESTS.push_back({ 1, 2, 3, 5 });
	ANSWERS.push_back(false);

	TESTS.push_back({ 3, 3, 3, 4, 5 });
	ANSWERS.push_back(true);

	TESTS.push_back({ 1, 2, 3, 5 });
	ANSWERS.push_back(false);

	TESTS.push_back({ 1, 2, 5 });
	ANSWERS.push_back(false);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = canPartition(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}