// 78.subsets.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
vector<vector<int>> subsets(vector<int>& nums) {
	int S = nums.size();
	int N = (1 << S);
	vector<vector<int>> res;
	for (int i = 0; i < N; ++i) 
	{
		vector<int> v;
		for (int j = 0; j < S; ++j)
		{
			if (i & (1 << j)) v.push_back(nums[j]);
		}
		res.push_back(v);
	}
	return res;
}

//////////////////////////////////////////////////////////////////////////
//vector<vector<int>> subsets(vector<int>& nums) {
//	vector<vector<int>> res(1);
//	for (int i = 0; i < nums.size(); i++) {
//		int cnt = res.size();
//		for (int j = 0; j < cnt; j++) {
//			vector<int> tmp = res[j];
//			tmp.push_back(nums[i]);
//			res.push_back(tmp);
//		}
//	}
//	return res;
//}

//////////////////////////////////////////////////////////////////////////
//void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> record, int n)
//{
//	if (n == nums.size()) return;
//	for (int i = n; i < nums.size(); i++)
//	{
//		record.push_back(nums[i]);
//		res.push_back(record);
//		backtrack(nums, res, record, i + 1);
//		record.pop_back();
//	}
//}
//
//vector<vector<int>> subsets(vector<int>& nums)
//{
//	vector<vector<int>> res;
//	vector<int> record;
//	res.push_back(record);
//	backtrack(nums, res, record, 0);
//	return res;
//}



int main()
{
	vector<vector<int>> TESTS;
	//vector<int> K;
	vector<vector<vector<int>>> ANSWERS;

	TESTS.push_back({ 1,2,3 });
	ANSWERS.push_back({ {}, {1}, {1,2}, {1,2,3}, {1,3}, {2}, {2,3}, {3} });

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = subsets(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}
