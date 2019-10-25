// 371.sum-of-two-integers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
int getSum(int a, int b)
{
	int c = a ^ b;
	unsigned int d = a & b;
#if 0
	// method one(faster but expend too much memory)
	return 0 != d ? getSum(c, d << 1) : c;
#else
	// method two(lower memory but slow)
	while (d)
	{
		d <<= 1;
		int t = c ^ d;
		d = c & d;
		c = t;
	}
	return c;
#endif
}



int main()
{
	vector<vector<int>> TESTS;
	//vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back({ 1,2 });
	ANSWERS.push_back(3);

	TESTS.push_back({ 2,1 });
	ANSWERS.push_back(3);

	TESTS.push_back({ 2,3 });
	ANSWERS.push_back(5);

	TESTS.push_back({ 0,1 });
	ANSWERS.push_back(1);

	//TESTS.push_back({ -2147483648​,-1 });
	//ANSWERS.push_back("0.5");


	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = getSum(TESTS[i][0], TESTS[i][1]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}