// 198.Rob.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;


int rob(vector<int>& nums)
{
	int sumOdd = 0;
	int sumEven = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i % 2 == 0)
		{
			sumOdd = max(sumOdd, sumEven);
			sumEven += nums[i];
		}
		else
		{
			sumEven = max(sumOdd, sumEven);
			sumOdd += nums[i];
		}
	}
	return max(sumOdd, sumEven);
}

//int rob(vector<int>& nums)
//{
//	int sumOdd = 0;
//	int sumEven = 0;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		if (i % 2 == 0)
//		{
//			sumEven += nums[i];
//			sumEven = max(sumOdd, sumEven);
//		}
//		else
//		{
//			sumOdd += nums[i];
//			sumOdd = max(sumOdd, sumEven);
//		}
//	}
//	return max(sumOdd, sumEven);
//}

//int rob(vector<int>& nums) 
//{
//	// 动态规划
//	if (nums.size() == 0) return 0;
//	if (nums.size() == 1)
//		return nums[0];
//	if (nums.size() == 2)
//		return max(nums[0], nums[1]);
//	nums[2] = nums[0] + nums[2];
//	if (nums.size() == 3)
//		return max(nums[1], nums[2]);
//	for (int i = 3; i < nums.size(); i++)
//	{
//		nums[i] = max(nums[i - 2] + nums[i], nums[i] + nums[i - 3]);
//	}
//	return max(nums[nums.size() - 1], nums[nums.size() - 2]);
//}

void initVectorInt(vector<int> &nums)
{
	//int A[] = { 1,2,3,1 };
	//int A[] = { 2,7,9,3,1 };
	int A[] = { 2,4,8,9,9,3 };
	//int A[] = { 1,3,1,3,100 };
	for (int i : A)
	{
		nums.push_back(i);
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> nums;
	initVectorInt(nums);
	cout << endl << rob(nums) << endl;
}
