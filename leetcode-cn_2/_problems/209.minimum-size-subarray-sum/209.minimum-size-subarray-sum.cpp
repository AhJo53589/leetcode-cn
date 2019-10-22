// 209.minimum-size-subarray-sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

int minSubArrayLen(int s, vector<int>& nums)
{
	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return nums[0] >= s ? 1 : 0;

	int iLen_min = INT_MAX;
	int low = 0;
	int high = 1;
	int sum = nums[low] + nums[high];
	while (low < nums.size() - 1)
	{
		if (nums[low] >= s) return 1;
		if (sum >= s)
		{
			iLen_min = min(iLen_min, high - low + 1);
			sum -= nums[low];
			low++;
		}
		else
		{
			high++;
			if (high == nums.size()) break;
			sum += nums[high];
		}
	}
	return iLen_min == INT_MAX ? 0 : iLen_min;
}

int main()
{
	string str = "[2,3,1,2,4,3]";
	int s = 7;
	vector<int> nums = StringToVectorInt(str);
	printVectorT(nums);
	int len = minSubArrayLen(s, nums);
	cout << "len = " << len << endl;
}
