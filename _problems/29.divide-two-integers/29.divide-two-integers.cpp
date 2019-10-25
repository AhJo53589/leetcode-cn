// 29.divide-two-integers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
int divide(int dividend, int divisor)
{
	if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
	int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
	long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
	while (m >= n)
	{
		long long t = n, p = 1;
		while (m >= (t << 1))
		{
			t <<= 1;
			p <<= 1;
		}
		m -= t;
		res += p;
	}
	return sign == 1 ? res : -res;
}


int main()
{
	vector<vector<int>> TESTS;
	//vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back({ 10,3 });
	ANSWERS.push_back(3);

	TESTS.push_back({ 7,-3 });
	ANSWERS.push_back(-2);

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = divide(TESTS[i][0], TESTS[i][1]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}