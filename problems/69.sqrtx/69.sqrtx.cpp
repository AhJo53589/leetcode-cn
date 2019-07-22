// 69.sqrtx.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

int mySqrt(int x)
{
	if (x == 0) return 0;
	if (x < 4) return 1;
	long long low = 1;
	long long high = x;
	while (low < high)
	{
		long long mid = low + (high - low) / 2;
		if (mid * mid <= x) low = mid + 1;
		else high = mid;
	}
	return low - 1;
}

int main()
{
	for (int i = 0; i < 100; i++)
	{
		cout << endl << "////////////////////////////////////" << endl;
		int f = mySqrt(i);
		cout << "x value = " << i << endl;
		cout << "Sqrt = " << f << endl;
		cout << "Answer = " << sqrt(i) << endl;
	}
}
