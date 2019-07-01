// 561.array-partition-i.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

#include "..\Common\Common.h"
using namespace std;

int arrayPairSum(vector<int>& nums)
{
	int sum = 0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i += 2)
	{
		sum += min(nums[i], nums[i + 1]);
	}
	return sum;
}

int main()
{
	string str = "[1,4,3,2]";
	vector<int> nums = StringToVectorInt(str);
	printVectorInt(nums);
	cout << arrayPairSum(nums) << endl;
}
