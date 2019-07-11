// 509.fibonacci-number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include <bitset>

using namespace std;


unordered_map<int, int> cache;

int fib(int N)
{
	if (cache.count(N)) return cache[N];

	if (N == 0) return 0;
	if (N == 1) return 1;
	return fib(N - 1) + fib(N - 2);
}

int main()
{
	for (int i = 0; i < 30; i++)
	{
		cout << i << ": " << fib(i) << endl;
	}
}
