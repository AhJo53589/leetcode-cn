// 171.excel-sheet-column-number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
int titleToNumber(string s)
{
	int res = 0;
	double i = 1;
	while (!s.empty())
	{
		res += (s.back() - 'A' + 1) * i;
		s.pop_back();
		i *= 26;
	}
	return res;
}

int main()
{
	vector<string> TESTS;
	//vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back({ "A" });
	ANSWERS.push_back(1);

	TESTS.push_back({ "AB" });
	ANSWERS.push_back(28);

	TESTS.push_back({ "ZY" });
	ANSWERS.push_back(701);

	TESTS.push_back({ "CFDGSXM" });
	ANSWERS.push_back(1000000001);

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = titleToNumber(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}
