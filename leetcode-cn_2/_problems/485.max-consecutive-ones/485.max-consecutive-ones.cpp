// 485.max-consecutive-ones.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

int findMaxConsecutiveOnes(vector<int>& nums)
{
	int len = 0;
	int k = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
		{
			len = max(len, k);
			k = 0;
			continue;
		}
		k++;
	}
	return max(len, k);
}

int main()
{
	string str = "[1,1,0,1,1,1]";
	vector<int> nums = StringToVectorInt(str);
	printVectorT(nums);
	int len = findMaxConsecutiveOnes(nums);
	cout << "len = " << len << endl;
}
