// 215.kth-largest-element-in-an-array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

int findKthLargest(vector<int>& nums, int k)
{
	int len = nums.size();
	bool bOrder = k <= len / 2;
	int t = bOrder ? k : len - k + 1;
	for (int j = 0; j < len - 1; j++)
	{
		for (int i = 0; i < len - 1 - j; i++)
		{
			if ([bOrder](int a, int b) { return bOrder ? a > b : b > a; }(nums[i], nums[i + 1]))
			{
				swap(nums[i], nums[i + 1]);
			}
		}
		if (t-- == 0) break;
	}
	return bOrder ? nums[len - k] : nums[k - 1];
}

//int findKthLargest(vector<int>& nums, int k) 
//{
//	int len = nums.size();
//	bool bOrder = k <= len / 2;
//	cout << "bOrder = " << bOrder << endl;
//
//	int t = bOrder ? k : len - k + 1;
//	for (int j = 0; j < len - 1; j++)
//	{
//		for (int i = 0; i < len - 1 - j; i++)
//		{
//			if ([bOrder](int a, int b) { return bOrder ? a > b : b > a; }(nums[i], nums[i + 1]))
//			{
//				swap(nums[i], nums[i + 1]);
//				cout << "swap(nums[" << i << "], nums[" << i + 1 << "]);" << endl;
//				printVectorInt(nums);
//			}
//		}
//		t--;
//		if (t == 0) break;
//		cout << "t = " << t << endl << endl;
//	}
//	return bOrder ? nums[len - k] : nums[k - 1];
//}

int main()
{
	vector<string> vStr;
	vector<int> vk;
	
	vStr.push_back("[3,2,1,5,6,4]");
	vk.push_back(2);

	vStr.push_back("[3,2,3,1,2,4,5,5,6,1]");
	vk.push_back(4);

	vStr.push_back("[1,2,3,4,5]");
	vk.push_back(4);

	vStr.push_back("[5,4,3,2,1]");
	vk.push_back(2);

	for (int i = 0; i < vStr.size(); i++)
	{
		vector<int> nums = StringToVectorInt(vStr[i]);
		printVectorT(nums);

		int res = findKthLargest(nums, vk[i]);
		printVectorT(nums);
		cout << "nums[" << vk[i] << "] = " << res << endl << endl;
	}
}
