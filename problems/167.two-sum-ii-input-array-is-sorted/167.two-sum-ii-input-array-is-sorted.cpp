// 167.two-sum-ii-input-array-is-sorted.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

vector<int> twoSum(vector<int>& numbers, int target)
{
	int low = 0;
	int high = numbers.size() - 1;
	while (low < high)
	{
		if (numbers[low] + numbers[high] > target) high--;
		else if (numbers[low] + numbers[high] < target) low++;
		else return { low + 1, high + 1 };
	}
	return { -1, -1 };
}

int main()
{
	string str = "[2, 7, 11, 15]";
	int target = 9;
	vector<int> nums = StringToVectorInt(str);
	printVectorT(nums);
	vector<int> res = twoSum(nums, target);
	printVectorT(res);
}
