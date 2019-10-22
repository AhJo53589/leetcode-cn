// 724.find-pivot-index.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;


int pivotIndex(vector<int>& nums) 
{
	if (nums.size() == 0) return -1;
	int sum_l = 0;
	int sum_r = 0;
	for (auto i : nums) sum_r += i;
	for (int i = 0; i < nums.size(); i++)
	{
		sum_r -= nums[i];
		if (sum_l == sum_r) return i;
		sum_l += nums[i];
	}
	return -1;
}


int main()
{
    std::cout << "Hello World!\n"; 
}
