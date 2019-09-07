// 11.container-with-most-water.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

int maxArea(vector<int>& nums)
{
	auto getArea = [nums](int low, int high) { return min(nums[low], nums[high]) * abs(low - high); };
	vector<int> left;
	vector<int> right;
	int iMax = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > iMax) left.push_back(i);
		iMax = max(iMax, nums[i]);
	}
	iMax = 0;
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		if (nums[i] > iMax) right.push_back(i);
		iMax = max(iMax, nums[i]);
	}
	iMax = 0;
	int i = 0;
	int j = 0;
	while (i < left.size() && j < right.size() && left[i] < right[j])
	{
		iMax = max(iMax, getArea(left[i], right[j]));
		nums[left[i]] < nums[right[j]] ? i++ : j++;
	}
	return iMax;
}

int main()
{
	vector<string> vStr;
	vector<int> vk;

	vStr.push_back("[1,8,6,2,5,4,8,3,7]");

	for (int i = 0; i < vStr.size(); i++)
	{
		vector<int> nums = StringToVectorInt(vStr[i]);
		printVectorT(nums);

		int res = maxArea(nums);
		cout << res << endl << endl;
	}
}
