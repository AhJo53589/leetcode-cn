﻿// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


// int main()
// {
// 	vector<vector<int>> TESTS;
// 	//vector<int> K;
// 	vector<bool> ANSWERS;
// 
// 	//TESTS.push_back(StringToVectorInt("[1,2,3,4,5]"));
// 	//ANSWERS.push_back(true);
// 
// 	//TESTS.push_back(StringToVectorInt("[5,4,3,2,1]"));
// 	//ANSWERS.push_back(false);
// 
// 	//TESTS.push_back(StringToVectorInt("[9,7,8,5,6,3,4,1,2]"));
// 	//ANSWERS.push_back(false);
// 
// 	//TESTS.push_back(StringToVectorInt("[9,7,8,5,6,1,4,2,3]"));
// 	//ANSWERS.push_back(true);
// 
// 	//TESTS.push_back(StringToVectorInt("[3,9,8,5,2,1,2,3,4]"));
// 	//ANSWERS.push_back(true);
// 
// 	//TESTS.push_back(StringToVectorInt("[5,1,5,5,2,5,4]"));
// 	//ANSWERS.push_back(true);
// 
// 	TESTS.push_back(StringToVectorInt("[1,1,-2,6]"));
// 	ANSWERS.push_back(false);
// 
// 	for (int j = 0; j < TESTS.size(); j++)
// 	{
// 		cout << endl << "/////////////////////////////" << endl;
// 		//auto ans = setZeroes(TESTS[j]);
// 		printVectorInt(TESTS[j]);
// 		bool ans = increasingTriplet(TESTS[j]);
// 		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[j]) << endl;
// 	}
// }


//////////////////////////////////////////////////////////////////////////
// 二维数组
//int main()
//{
//	vector<vector<vector<int>>> TESTS;
//	//vector<int> K;
//	vector<vector<vector<int>>> ANSWERS;
//
//	TESTS.push_back(StringToVectorVectorInt("[[1, 0]]"));
//	ANSWERS.push_back(StringToVectorVectorInt("[[0, 0]]"));
//
//	TESTS.push_back(StringToVectorVectorInt("[[1, 0, 3]]"));
//	ANSWERS.push_back(StringToVectorVectorInt("[[0, 0, 0]]"));
//
//	TESTS.push_back(StringToVectorVectorInt("[[1, 1, 1],[1, 0, 1],[1, 1, 1]]"));
//	ANSWERS.push_back(StringToVectorVectorInt("[[1, 0, 1],[0, 0, 0],[1, 0, 1]]"));
//
//	TESTS.push_back(StringToVectorVectorInt("[[0, 1, 2, 0],[3, 4, 5, 2],[1, 3, 1, 5]]"));
//	ANSWERS.push_back(StringToVectorVectorInt("[[0, 0, 0, 0],[0, 4, 5, 0],[0, 3, 1, 0]]"));
//
//	for (int j = 0; j < TESTS.size(); j++)
//	{
//		cout << endl << "/////////////////////////////" << endl;
//		//auto ans = setZeroes(TESTS[j]);
//		printVectorVectorInt(TESTS[j]);
//		setZeroes(TESTS[j]);
//		cout << checkAnswer<decltype(TESTS[j])>(TESTS[j], ANSWERS[j]) << endl;
//	}
//}


//////////////////////////////////////////////////////////////////////////
// TreeNode
//int main()
//{
//	vector<TreeNode *> N;
//	vector<int> K;
//	vector<bool> A;
//
//	N.push_back(StringToTreeNode("3,9,20,null,null,15,7"));
//	//K.push_back(3);
//	A.push_back(true);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,null,null,4,4"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	for (int j = 0; j < N.size(); j++)
//	{
//		cout << endl << "///////////////////////////////////////" << endl;
//		cout << N[j] << endl;
//		//DrawTreeNode(N[j]);
//
//		bool ans = isBalanced(N[j]);
//		cout << checkAnswer<bool>(ans, A[j]) << endl;
//		//DrawTreeNode(ans);
//
//	}
//}


//////////////////////////////////////////////////////////////////////////
// List Node
//int main()
//{
//	vector<ListNode *> lists;
//	ListNode *pHead = nullptr;
//	StringToListNode(&pHead, "[4,7,5,3]");
//	lists.push_back(pHead);
//	pHead = nullptr;
//
//	for (auto p : lists)
//	{
//		PrintLinkList(p);
//		pHead = sortList(p);
//		PrintLinkList(pHead);
//		cout << endl;
//	}
//}


