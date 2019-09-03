// 134.gas-station.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//	int total = 0;
//	int sum = 0;
//	int start = 0;
//	for (int i = 0; i < gas.size(); i++)
//	{
//		int sub = gas[i] - cost[i];
//		total += sub;
//		sum += sub;
//		if (sum < 0)
//		{
//			sum = 0;
//			start = i + 1;
//		}
//	}
//
//	return total < 0 ? -1 : start;
//}

//////////////////////////////////////////////////////////////////////////
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	int n = gas.size();
	int f = 0;
	vector<int> fuel(n, 0);
	for (int i = 0; i < n; i++)
	{
		fuel[i] = gas[i] - cost[i];
		f += fuel[i];
	}
	if (f < 0) return -1;

	for (int i = 0; i < n; i++)
	{
		if (fuel[i] < 0) continue;
		f = fuel[i];

		int j = (i + 1) % n;
		while (true)
		{
			f += fuel[j];
			if (f < 0)
			{
				i = j;
				break;
			}

			j = (j + 1) % n;
			if (j == i) return i;
		}
	}
	return -1;
}



int main()
{
	vector<vector<int>> TESTS;
	vector<vector<int>> K;
	vector<int> ANSWERS;

	TESTS.push_back({ 1,2,3,4,5 });
	K.push_back({ 3,4,5,1,2 });
	ANSWERS.push_back(3);

	TESTS.push_back({ 2,3,4 });
	K.push_back({ 3,4,3 });
	ANSWERS.push_back(-1);

	TESTS.push_back({ 2 });
	K.push_back({ 2 });
	ANSWERS.push_back(0);

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = canCompleteCircuit(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}
