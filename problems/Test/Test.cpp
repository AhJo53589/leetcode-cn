// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>

#include "..\Common\GraphNode.h"
#include "..\Common\TreeNode.h"
using namespace std;

//int findTargetSumWays(vector<int>& nums, int S) {
//	int sum = 0;
//	for (int n : nums) sum += n;
//	if (sum < S || (S + sum) % 2 != 0) return 0;
//	int right = (S + sum) >> 1;	// int right = (S + sum) / 2;
//	vector<int> dp(right + 1, 0);
//	dp[0] = 1;
//	for (int d : nums) {
//		for (int i = right; i >= d; i--) dp[i] += dp[i - d];
//	}
//	return dp[right];
//}

int findTargetSumWays(vector<int>& nums, int S, int iIndex, int iSum)
{
	if (iIndex == nums.size() - 1)
	{
		if (nums[iIndex] == 0 && iSum == S) return 2;
		if (iSum + nums[iIndex] == S) return 1;
		if (iSum - nums[iIndex] == S) return 1;
		return 0;
	}

	int iRst = 0;
	iRst += findTargetSumWays(nums, S, iIndex + 1, iSum + nums[iIndex]);
	iRst += findTargetSumWays(nums, S, iIndex + 1, iSum - nums[iIndex]);
	return iRst;
}

int findTargetSumWays(vector<int>& nums, int S) 
{
	return findTargetSumWays(nums, S, 0, 0);
}


void initVectorInt(vector<int> &nums)
{
	//int A[] = { 1,2,3,1 };
	//int A[] = { 2,7,9,3,1 };
	//int A[] = { 2,4,8,9,9,3 };
	int A[] = { 1, 1, 1, 1, 1 };
	for (int i : A)
	{
		nums.push_back(i);
		cout << i << " ";
	}
	cout << endl;
}

void printfVectorInt(vector<int> &nums)
{
	for (int i : nums)
	{
		cout << i << " ";
	}
	cout << endl;
}


int main()
{
	int S = 3;
	vector<int> nums;
	initVectorInt(nums);
	cout << endl << findTargetSumWays(nums, S) << endl;
}
