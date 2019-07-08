// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include "..\Common\TreeNode.h"
#include "..\Common\ListNode.h"
using namespace std;


int missingNumber(vector<int>& nums) 
{
	//int sumA = (0 + nums.size() - 1 + 1) * (nums.size() + 1) / 2;
	int sumA = nums.size() * (nums.size() + 1) / 2;
	int sumB = 0;
	for (auto i : nums) sumB += i;
	return sumA - sumB;
}

int main()
{
	string str = "[9,6,4,2,3,5,7,0,1]";
	vector<int> nums = StringToVectorInt(str);
	printVectorInt(nums);
	cout << endl << missingNumber(nums) << endl;
}
