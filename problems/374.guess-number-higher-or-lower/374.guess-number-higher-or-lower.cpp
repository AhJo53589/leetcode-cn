// 374.guess-number-higher-or-lower.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


int guess(int num)
{
	int n = 6;
	if (num == n) return 0;
	return (num < n) ? 1 : -1;
}

int guessNumber(int n)
{
	int low = 0;
	int high = n;
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		int guessResult = guess(mid);
		if (guessResult == 0) return mid;
		else if (guessResult == 1) low = mid + 1;
		else high = mid;
	}
	return low;
}

int main()
{
	cout << guessNumber(10) << endl;
}
