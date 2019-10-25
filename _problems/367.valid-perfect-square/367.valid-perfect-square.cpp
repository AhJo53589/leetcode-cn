// 367.valid-perfect-square.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


bool isPerfectSquare(int num)
{
	if (num == 0) return true;
	if (num == 1) return true;
	long long low = 1;
	long long high = num;
	while (low < high)
	{
		long long mid = low + (high - low) / 2;
		if (mid * mid == num) return true;
		else if (mid * mid < num) low = mid + 1;
		else high = mid;
	}
	return false;
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		cout << endl << "///////////////////////" << endl;
		cout << i << " is Perfect Square ? " << isPerfectSquare(i) << endl;
	}
}
