// 7.Reverse.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

//int reverse(int x)
//{
//	long result = 0;
//	while (x != 0) {
//		result = result * 10 + x % 10;
//		x /= 10;
//	}
//	if (result > 2147483647 || result < -2147483648) {
//		return 0;
//	}
//	return (int)result;
//}

int reverse(int x)
{
	int result = 0;
	while (x != 0)
	{
		if (result > INT_MAX / 10 || result < INT_MIN / 10)
		{
			return 0;
		}
		result = result * 10 + x % 10;
		x = x / 10;
	}
	return result;
}

int main()
{
	std::cout << "Hello World!\n";
}

