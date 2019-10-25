// 219.contains-duplicate-ii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	if (nums.empty()) return false;
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); i++)
	{
		if (!m.count(nums[i])) m[nums[i]] = i;
		else if (i - m[nums[i]] <= k) return true;
		else m[nums[i]] = i;
	}
	return false;
}

int main()
{
	//int k = 2;
	//vector<int> nums = StringToVectorInt("[1,2,3,1,2,3]");
	//int k = 3;
	//vector<int> nums = StringToVectorInt("[1,2,3,1]");
	int k = 1;
	vector<int> nums = StringToVectorInt("[1]");

	cout << containsNearbyDuplicate(nums, k) << endl;
}
