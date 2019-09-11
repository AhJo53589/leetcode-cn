// 674.longest-continuous-increasing-subsequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;


//////////////////////////////////////////////////////////////////////////
int findLengthOfLCIS(vector<int>& nums)
{
	if (nums.size() == 0) return 0;
	int ans = 1;
	int temp = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] > nums[i - 1])
		{
			temp++;
			ans = max(ans, temp);
		}
		else
		{
			temp = 1;
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
//int findLengthOfLCIS(vector<int>& nums)
//{
//	if (nums.size() == 0) return 0;
//	vector<int> dp(nums.size(), 1);
//	int ans = 1;
//	for (int i = 1; i < nums.size(); i++)
//	{
//		if (nums[i] > nums[i - 1])
//		{
//			dp[i] = dp[i - 1] + 1;
//			ans = max(ans, dp[i]);
//		}
//	}
//	return ans;
//}

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
	//vector<string> K;
	vector<int> ANSWERS;

	TESTS.push_back({ 1,3,5,4,7 });
	ANSWERS.push_back(3);

	TESTS.push_back({ 2,2,2,2,2 });
	ANSWERS.push_back(1);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = findLengthOfLCIS(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}