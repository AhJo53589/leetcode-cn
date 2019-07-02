// 27.remove-element.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

#include "..\Common\Common.h"
using namespace std;

void swap(int &a, int &b)
{
	if (a == b) return;
	a ^= b;
	b ^= a;
	a ^= b;
}

int removeElement(vector<int>& nums, int val)
{
	int len = 0;
	int low = 0;
	int high = nums.size() - 1;

	while (low <= high)
	{
		if (nums[low] == val) swap(nums[low], nums[high--]);
		else low++;
	}

	return low;
}

int main()
{
	vector<string> vStr;
	vector<int> vVal;
	string str = "[3,2,2,3]";
	int val = 3;
	vStr.push_back(str);
	vVal.push_back(val);

	str = "[0,1,2,2,3,0,4,2]";
	val = 2;
	vStr.push_back(str);
	vVal.push_back(val);

	str = "[]";
	val = 1;
	vStr.push_back(str);
	vVal.push_back(val);

	str = "[1]";
	val = 1;
	vStr.push_back(str);
	vVal.push_back(val);

	for (int t = 0; t < vStr.size(); t++)
	{
		vector<int> nums = StringToVectorInt(vStr[t]);
		printVectorInt(nums);

		// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
		int len = removeElement(nums, vVal[t]);

		// 在函数里修改输入数组对于调用者是可见的。
		// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
		cout << "val = " << vVal[t] << endl;
		cout << "len = " << len << endl;
		for (int i = 0; i < len; i++)
		{
			cout << nums[i] << " ";
		}
		cout << endl;
		cout << "------------------" << endl << endl;
	}
}
