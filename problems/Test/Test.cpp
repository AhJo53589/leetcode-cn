﻿// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
int leastInterval(vector<char>& tasks, int n)
{
	array<int, 26> task_count = {};
	vector<int> task_order;

	for (auto &c : tasks)
	{
		task_count[c - 'A']++;
	}
	for (int i = 0; i < task_count.size(); i++)
	{
		if (task_count[i] == 0) continue;
		task_order.push_back(task_count[i]);
	}
	sort(task_order.rbegin(), task_order.rend());

	int res = 0;
	while (!task_order.empty())
	{
		int count = 0;
		for (int i = 0; i < task_order.size(); i++)
		{
			task_order[i]--;
			count++;
			if (count == n + 1) break;
		}
		sort(task_order.rbegin(), task_order.rend());
		while (!task_order.empty() && task_order.back() == 0) task_order.pop_back();

		res += task_order.empty() ? count : n + 1;
	}

	return res;
}



int main()
{
	vector<vector<char>> TESTS;
	vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back({ 'A','A','A','B','B','B' });
	K.push_back(2);
	ANSWERS.push_back(8);

	TESTS.push_back({ 'A','B','C','B','C','C','D','E' });
	K.push_back(2);
	ANSWERS.push_back(8);

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = leastInterval(TESTS[i], K[i]);
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


