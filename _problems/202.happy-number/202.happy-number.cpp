// 202.happy-number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

//#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;


unordered_set<int> visited;
bool isHappy(int n)
{
	if (visited.count(n)) return false;
	visited.insert(n);

	int s = 0;
	while (n > 0)
	{
		s += pow((n % 10), 2);
		n /= 10;
	}
	if (s == 1) return true;
	return isHappy(s);
}

int main()
{
	for (int i = 1; i < 100; i++)
	{
		cout << i << " is Happy? " << isHappy(i) << endl;
	}
}
