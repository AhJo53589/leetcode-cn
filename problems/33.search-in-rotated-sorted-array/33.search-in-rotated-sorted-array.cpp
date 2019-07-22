// 33.search-in-rotated-sorted-array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


int lowerBound(vector<int> &nums, int target, int low, int high)
{
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] == target) return mid;
		if (nums[low] <= nums[mid])
		{
			if (nums[low] <= target && target <= nums[mid])
			{
				high = mid;
			}
			else
			{
				low = mid + 1;
			}
		}
		else if (nums[mid] <= nums[high - 1])
		{
			if (nums[mid] <= target && target <= nums[high - 1])
			{
				low = mid + 1;
			}
			else
			{
				high = mid;
			}
		}
	}
	return low;
}

int search(vector<int>& nums, int target)
{
	int i = lowerBound(nums, target, 0, nums.size());
	if (i == nums.size()) return -1;
	return (nums[i] == target) ? i : -1;
}

int main()
{
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << endl << "/////////////////////////////" << endl;
	//	vector<int> nums = StringToVectorInt("[4,5,6,7,0,1,2]");
	//	printVectorInt(nums);
	//	cout << "Find = " << i << endl;
	//	cout << "Index = " << search(nums, i) << endl;
	//}

	for (int i = 0; i < 5; i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		vector<int> nums = StringToVectorInt("[3,1]");
		printVectorInt(nums);
		cout << "Find = " << i << endl;
		cout << "Index = " << search(nums, i) << endl;
	}
}
