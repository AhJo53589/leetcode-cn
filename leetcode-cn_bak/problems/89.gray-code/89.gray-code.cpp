// 89.gray-code.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <array>
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
//vector<int> grayCode(int n)
//{
//	if (n == 0) return { 0 };
//	if (n == 1) return { 0, 1 };
//
//	vector<int> prev = grayCode(n - 1);
//	vector<int> res;
//	bool bFlag = true;
//	for (int i = 0; i < prev.size(); i += 2)
//	{
//		int add1 = prev[i] & 1;
//		int add2 = (add1 == 1) ? 0 : 1;
//		if (!bFlag) swap(add1, add2);
//		res.push_back((prev[i] << 1) + add1);
//		res.push_back((prev[i] << 1) + add2);
//
//		add1 = prev[i + 1] & 1;
//		add2 = (add1 == 1) ? 0 : 1;
//		if (!bFlag) swap(add1, add2);
//		res.push_back((prev[i + 1] << 1) + add1);
//		res.push_back((prev[i + 1] << 1) + add2);
//
//		bFlag = !bFlag;
//	}
//	return res;
//}

//////////////////////////////////////////////////////////////////////////
vector<int> grayCode(int n) {
	vector<int> res;
	for (int i = 0; i < (1 << n); ++i)
		res.push_back(i ^ (i >> 1));
	return res;
}



int main()
{
	vector<int> TESTS;
	//vector<int> K;
	vector<vector<int>> ANSWERS;

	TESTS.push_back(0);
	ANSWERS.push_back({ 0 });

	TESTS.push_back(2);
	ANSWERS.push_back({ 0,1,3,2 });

	TESTS.push_back(3);
	ANSWERS.push_back({ 0,1,3,2,6,7,5,4 });

	TESTS.push_back(4);
	ANSWERS.push_back({ 0,1,3,2,6,7,5,4,12,13,15,14,10,11,9,8 });

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = grayCode(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}
