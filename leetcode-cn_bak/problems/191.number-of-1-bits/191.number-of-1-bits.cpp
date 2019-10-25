// 191.number-of-1-bits.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int hammingWeight(uint32_t n)
{
	int sum = 0;
	while (n != 0)
	{
		n &= (n - 1);
		sum++;
	}
	return sum;
}

int main()
{
    std::cout << "Hello World!\n"; 
}

