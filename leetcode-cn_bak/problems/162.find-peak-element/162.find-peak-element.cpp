// 162.find-peak-element.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

int findPeakElement(vector<int>& nums)
{
	int low = 0;
	int high = nums.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		bool l = (mid == 0 || nums[mid - 1] < nums[mid]);
		bool r = (mid == nums.size() - 1 || nums[mid + 1] < nums[mid]);
		if (l && r) return mid;
		else if (l) low = mid + 1;
		else high = mid;
	}
	return (low < nums.size()) ? low : -1;
}

int main()
{
	vector<string> str;
	str.push_back("[1,2,3,1]");
	str.push_back("[1,2,1,3,5,6,4]");

	for (auto s : str)
	{
		cout << endl << "/////////////////////////////" << endl;
		vector<int> nums = StringToVectorInt(s);
		printVectorT(nums);
		cout << "Find Peak Element = " << findPeakElement(nums) << endl;
	}
}
