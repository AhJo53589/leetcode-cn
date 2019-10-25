// 120.triangle.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//////////////////////////////////////////////////////////////////////////
int minimumTotal(vector<vector<int>>& triangle)
{
	if (triangle.empty()) return 0;
	vector<int> dp(triangle.back().begin(), triangle.back().end());

	for (int i = triangle.size() - 2; i >= 0; i--)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
		}
	}
	return dp[0];
}



int main()
{
	vector<vector<vector<int>>> TESTS;
	//vector<vector<int>> K;
	vector<int> ANSWERS;

	TESTS.push_back({ {2}, {3,4},{6,5,7},{4,1,8,3} });
	ANSWERS.push_back(11);

	TESTS.push_back({ { -10 } });
	ANSWERS.push_back(-10);


	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = minimumTotal(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}
