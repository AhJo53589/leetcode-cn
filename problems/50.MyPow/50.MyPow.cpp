// 50.MyPow.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

//double myPow(double x, int n)	// 12ms
//{
//	double res = 1.0;
//	for (int i = n; i != 0; i /= 2) {
//		if (i % 2 != 0) {
//			res *= x;
//		}
//		x *= x;
//	}
//	return  n < 0 ? 1 / res : res;
//}

double myPow(double x, int n)	// 4ms
{
	switch (n)
	{
	case -1:
		return 1 / x;
	case 0:
		return 1.0;
	case 1:
		return x;
	case 2:
		return x * x;
	}

	return myPow(myPow(x, 2), n / 2) * myPow(x, n % 2);
}

int main()
{
    std::cout << "Hello World!\n"; 
}
