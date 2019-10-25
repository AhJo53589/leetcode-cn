// 231.power-of-two.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

bool isPowerOfTwo(int n) 
{
	if (n <= 0) return false;
	return ((n&(n - 1)) == 0);
}

int main()
{
    std::cout << "Hello World!\n"; 
}

