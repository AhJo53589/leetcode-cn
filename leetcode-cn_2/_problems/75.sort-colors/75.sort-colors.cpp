// 75.sort-colors.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


void sortColors(vector<int>& nums)
{
	int low = 0;
	int high = nums.size() - 1;
	while (low < nums.size() && nums[low] == 0) low++;
	while (high > low && nums[high] == 2) high--;
	for (int i = 0; i < nums.size(); i++)
	{
		auto swap = [](int &a, int &b) {if (a == b) return; a ^= b; b ^= a; a ^= b; };
		if (i > low && nums[i] == 0) swap(nums[i--], nums[low++]);
		else if (i < high && nums[i] == 2) swap(nums[i--], nums[high--]);
	}
}

int main()
{
	vector<string> vStr;
	string str = "[2,0,2,1,1,0]";
	vStr.push_back(str);
	str = "[1,0]";
	vStr.push_back(str);
	str = "[2,0]";
	vStr.push_back(str);
	str = "[1,2,0]";
	vStr.push_back(str);

	for (auto s : vStr)
	{
		vector<int> nums = StringToVectorInt(s);
		printVectorT(nums);

		sortColors(nums);
		printVectorT(nums);
		cout << endl;
	}
}
