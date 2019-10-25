// 300.longest-increasing-subsequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
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

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//int lengthOfLIS(vector<int>& nums)
//{
//	if (nums.size() == 0) return 0;
//	vector<int> log(nums.size(), INT_MAX);
//	int out = 0;
//	for (int pos = 0; pos < nums.size(); pos++)
//	{
//		int pos1 = 0, pos2 = nums.size() - 1;
//		while (pos2 > pos1)
//		{
//			int mid = (pos1 + pos2) / 2;
//			if (log[mid] >= nums[pos]) pos2 = mid;
//			else pos1 = mid + 1;
//		}
//		log[pos1] = nums[pos];
//		out = max(out, pos1 + 1);
//	}
//	return out;
//}
//////////////////////////////////////////////////////////////////////////
int lengthOfLIS(vector<int>& nums)
{
	if (nums.empty()) return 0;
	int res = 0;
	vector<int> dp(nums.size(), 0);
	for (int i = 1; i < nums.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				res = max(res, dp[i]);
			}
		}
	}
	return res + 1;
}

int main()
{
	vector<vector<int>> TESTS;
	//vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back({ 10,9,2,5,3,7,101,18 });
	ANSWERS.push_back(4);

	TESTS.push_back({ 10,22,9,33,21,50,41,60,80 });
	ANSWERS.push_back(6);

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = lengthOfLIS(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}
