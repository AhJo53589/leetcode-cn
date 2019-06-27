// 747.largest-number-at-least-twice-of-others.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int dominantIndex(vector<int>& nums) 
{
	if (nums.size() == 0) return -1;
	if (nums.size() == 1) return 0;
	int max = nums[0] < nums[1] ? 1 : 0;
	int second = nums[0] < nums[1] ? 0 : 1;
	for (int i = 2; i < nums.size(); i++)
	{
		if (nums[i] >= nums[max])
		{
			second = max;
			max = i;
		}
		else if (nums[i] >= nums[second])
		{
			second = i;
		}
	}
	if (nums[max] >= nums[second] * 2) return max;
	return -1;
}

int main()
{
    std::cout << "Hello World!\n"; 
}

