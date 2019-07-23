// 34.find-first-and-last-position-of-element-in-sorted-array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


//int lowerBound(vector<int> &nums, int target, int low, int high)
//{
//	if (low >= high) return low;
//	int mid = low + (high - low) / 2;
//	if (nums[mid] < target) return lowerBound(nums, target, mid + 1, high);
//	else return lowerBound(nums, target, low, mid);
//}

int lowerBound(vector<int> &nums, int target, int low, int high)
{
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] < target) low = mid + 1;
		else high = mid;
	}
	return low;
}

vector<int> searchRange(vector<int>& nums, int target)
{
	int l = lowerBound(nums, target, 0, nums.size());
	if (l < nums.size() && nums[l] == target)
	{
		int r = lowerBound(nums, target + 1, l, nums.size());
		return { l, r - 1 };
	}
	return { -1,-1 };
}

int main()
{
	vector<string> str;
	vector<int> target;
	vector<pair<int, int>> answer;
	str.push_back("[5,7,7,8,8,10]");
	target.push_back(8);
	answer.push_back({ 3,4 });

	str.push_back("[5,7,7,8,8,10]");
	target.push_back(6);
	answer.push_back({ -1,-1 });

	for (int i = 0; i < str.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		vector<int> nums = StringToVectorInt(str[i]);
		printVectorInt(nums);
		cout << "Find = " << target[i] << endl;
		cout << "Pos = ";
		vector<int> a = searchRange(nums, target[i]);
		printVectorInt(a);
		cout << "Answer = " << answer[i].first << " , " << answer[i].second << endl;
	}
}
