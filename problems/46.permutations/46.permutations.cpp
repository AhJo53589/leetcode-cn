// 46.permutations.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


//////////////////////////////////////////////////////////////////////////
void backtrack(vector<int> &nums, vector<vector<int>> &res, int i)
{
	if (i == nums.size()) res.push_back(nums);

	for (int j = i; j < nums.size(); j++)
	{
		swap(nums[i], nums[j]);
		backtrack(nums, res, i + 1);
		swap(nums[i], nums[j]);
	}
}

vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> res;
	backtrack(nums, res, 0);
	return res;
}



int main()
{
	vector<vector<int>> TESTS;
	//vector<int> K;
	vector<vector<vector<int>>> ANSWERS;

	TESTS.push_back({ 1,2,3 });
	ANSWERS.push_back({ {1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,2,1}, {3,1,2} });

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = permute(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}
