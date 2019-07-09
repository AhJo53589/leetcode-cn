// 80.remove-duplicates-from-sorted-array-ii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


int removeDuplicates(vector<int>& nums)
{
	int iLen = nums.size();
	if (nums.size() < 2) return iLen;

	int iIndex = 1;
	for (int i = 2; i < iLen; i++)
	{
		if (nums[i] != nums[iIndex - 1])
		{
			nums[++iIndex] = nums[i];
		}
	}
	return iIndex + 1;
}

int main()
{
	string str = "[0,0,1,1,1,1,2,3,3]";
	vector<int> nums = StringToVectorInt(str);
	printVectorInt(nums);

	// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
	int len = removeDuplicates(nums);
	cout << len << endl;

	// 在函数里修改输入数组对于调用者是可见的。
	// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
	for (int i = 0; i < len; i++)
	{
		cout << nums[i];
	}
}