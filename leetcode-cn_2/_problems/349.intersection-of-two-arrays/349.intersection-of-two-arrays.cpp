// 349.intersection-of-two-arrays.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	unordered_set<int> set1;
	unordered_set<int> set2;
	for (auto n : nums1) set1.insert(n);
	for (auto n : nums2) set2.insert(n);
	vector<int> rst;
	for (auto n1 : set1)
	{
		for (auto n2 : set2)
		{
			if (n1 == n2) rst.push_back(n1);
		}
	}
	return rst;
}

int main()
{
	vector<int> nums1 = StringToVectorInt("[4,9,5]");
	vector<int> nums2 = StringToVectorInt("[9,4,9,8,4]");

	vector<int> rst = intersection(nums1, nums2);
	printVectorT(rst);
}
