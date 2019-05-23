// 121.MaxProfit.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

#include "..\Common\TreeNode.h"
using namespace std;

int maxProfit(vector<int>& prices)
{
	int minPrice = INT_MAX;
	int maxProfit = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		minPrice = min(minPrice, prices[i]);
		maxProfit = max(maxProfit, prices[i] - minPrice);
	}
	return maxProfit;
}

void initVectorInt(vector<int> &nums)
{
	int A[] = { 7,1,5,3,6,4 };
	//int A[] = { 7,6,4,3,1 };
	//int A[] = { 1,2,3,4,5 };
	//int A[] = { 2,1,2,0,1 };
	for (int i : A)
	{
		nums.push_back(i);
		cout << i << " ";
	}
}

int main()
{
	vector<int> nums;
	initVectorInt(nums);
	cout << endl << maxProfit(nums) << endl;
}
