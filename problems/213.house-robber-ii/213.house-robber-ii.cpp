// 213.house-robber-ii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

int rob(vector<int>& nums)
{
	if (nums.size() == 1) return nums[0];

	int sumOdd[2] = { 0, 0 };	// 0 == head, 1 == tail
	int sumEven[2] = { 0, 0 };
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i == 0 && j == 1) continue;	// head only
			if (i == nums.size() - 1 && j == 0) continue;	// tail only
			if (i % 2 == 0)
			{
				sumOdd[j] = max(sumOdd[j], sumEven[j]);
				sumEven[j] += nums[i];
			}
			else
			{
				sumEven[j] = max(sumOdd[j], sumEven[j]);
				sumOdd[j] += nums[i];
			}
		}
	}

	for (int j = 0; j < 2; j++)
	{
		sumOdd[j] = max(sumOdd[j], sumEven[j]);
	}
	return max(sumOdd[0], sumOdd[1]);
}

int main()
{
	vector<int> nums = StringToVectorInt("[1]");

	//vector<int> nums = StringToVectorInt("[2,3,2]");
	//vector<int> nums = StringToVectorInt("[1,2,3,1]");
	//vector<int> nums = StringToVectorInt("[2,1,1,4,1,5]");

	cout << rob(nums) << endl;
}
