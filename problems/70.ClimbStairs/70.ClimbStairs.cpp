// 70.ClimbStairs.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int climbStairs(int n)
{
	if (n <= 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	int s1 = 1;
	int s2 = 2;
	int ret = 0;
	for (int i = 3; i <= n; i++)
	{
		ret = s1 + s2;
		s1 = s2;
		s2 = ret;
	}
	return ret;
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		cout << climbStairs(i) << endl;
	}
}
