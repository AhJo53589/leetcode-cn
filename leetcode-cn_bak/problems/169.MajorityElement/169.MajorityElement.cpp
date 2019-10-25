// 169.MajorityElement.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums)
{
	int res = 0, cnt = 0;
	for (int num : nums) 
	{
		if (cnt == 0) 
		{ 
			res = num;
			++cnt; 
		}
		else
		{
			(num == res) ? ++cnt : --cnt;
		}
	}
	return res;
}


int main()
{
    std::cout << "Hello World!\n"; 
}

