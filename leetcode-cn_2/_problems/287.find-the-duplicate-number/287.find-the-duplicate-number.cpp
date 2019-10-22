// 287.find-the-duplicate-number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

//int findDuplicate(vector<int>& nums)
//{
//	unordered_set<int> s;
//	for (auto i : nums)
//	{
//		if (s.count(i)) return i;
//		s.insert(i);
//	}
//	return nums[0];
//}

int findDuplicate(vector<int>& nums) {
	int low = nums[0];
	int fast = nums[nums[0]];
	while (low != fast)
	{
		low = nums[low];
		fast = nums[nums[fast]];
	}
	low = 0;
	while (low != fast)
	{
		low = nums[low];
		fast = nums[fast];
	}
	return fast;
}

int main()
{
	vector<string> str;
	str.push_back("[1,3,4,2,2]");
	str.push_back("[3,1,3,4,2]");

	for (auto s : str)
	{
		cout << endl << "/////////////////////////////" << endl;
		vector<int> nums = StringToVectorInt(s);
		printVectorT(nums);
		cout << "Find Duplicate = " << findDuplicate(nums) << endl;
	}
}
