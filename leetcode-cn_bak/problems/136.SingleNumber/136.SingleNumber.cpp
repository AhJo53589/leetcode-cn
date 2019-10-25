// 136.SingleNumber.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <numeric>		// std::accumulate
#include <functional>	// std::bit_xor


using namespace std;

int singleNumber(vector<int>& nums)
{
	return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
}

int main()
{
    std::cout << "Hello World!\n"; 
}
