// 62.unique-paths.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
int uniquePaths(int m, int n)
{
	int dp[101][101] = { 0 };
	for (int i = 0; i < m; i++)
	{
		dp[i][0] = 1;
	}
	for (int j = 0; j < n; j++)
	{
		dp[0][j] = 1;
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}

//////////////////////////////////////////////////////////////////////////
//int uniquePaths(int m, int n)
//{
//	if (m == 1 || n == 1) return 1;
//	return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
//}

int main()
{
	vector<vector<int>> TESTS;
	//vector<string> K;
	vector<int> ANSWERS;

	TESTS.push_back({ 3,2 });
	ANSWERS.push_back(3);

	TESTS.push_back({ 7,3 });
	ANSWERS.push_back(28);

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = uniquePaths(TESTS[i][0], TESTS[i][1]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}