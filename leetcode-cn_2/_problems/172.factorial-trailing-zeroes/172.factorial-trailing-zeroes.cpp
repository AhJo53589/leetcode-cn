// 172.factorial-trailing-zeroes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
int trailingZeroes(int n)
{
	int res = 0;
	while (n)
	{
		res += n / 5;
		n /= 5;
	}
	return res;
}

int main()
{
	vector<int> TESTS;
	//vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back({ 3 });
	ANSWERS.push_back(0);

	TESTS.push_back({ 5 });
	ANSWERS.push_back(1);

	TESTS.push_back({ 5 });
	ANSWERS.push_back(1);

	TESTS.push_back({ 10 });
	ANSWERS.push_back(2);

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = trailingZeroes(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}
