// 153.find-minimum-in-rotated-sorted-array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


int findMin(vector<int>& nums)
{
	if (nums.empty()) return -1;
	if (nums.size() == 1) return nums[0];
	int low = 0;
	int high = nums.size();
	if (low == 0 && nums[low] < nums[nums.size() - 1]) return nums[low];
	if (high - 2 != 0 && high - 1 != 0 && nums[high - 1] < nums[high - 2]) return nums[high - 1];
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (low != 0 && nums[low] < nums[low - 1]) return nums[low];
		if (mid != 0 && nums[mid] < nums[mid - 1]) return nums[mid];
		if (nums[low] <= nums[mid]) low = mid + 1;
		//else if (nums[mid] <= nums[high - 1]) high = mid;
		else high = mid;
	}
	return (low < nums.size()) ? nums[low] : -1;
}

//int findMin(vector<int>& nums) {
//	int lens = nums.size();
//	int i = 0;
//	int j = lens - 1;
//	while (i < j)
//	{
//		int mid = i + (j - i) / 2;
//		if (nums[mid] > nums[j])
//		{
//			i = mid + 1;
//		}
//		else
//		{
//			j = mid;
//		}
//	}
//	return nums[i];
//}

int main()
{
	vector<string> str;
	str.push_back("[3,4,5,1,2]");
	str.push_back("[4,5,6,7,0,1,2]");
	str.push_back("[4,5,0,1,2]");
	str.push_back("[2,3,1]");
	str.push_back("[2,1]");
	str.push_back("[1,2]");
	str.push_back("[1]");

	for (auto s : str)
	{
		cout << endl << "/////////////////////////////" << endl;
		vector<int> nums = StringToVectorInt(s);
		printVectorInt(nums);
		cout << "Find Min = " << findMin(nums) << endl;
	}
}
