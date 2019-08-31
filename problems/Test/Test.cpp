// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//int coinChange(vector<int>& coins, int amount)
//{
//	if (amount == 0) return 0;
//	sort(coins.begin(), coins.end());
//	vector<int> _in;
//	vector<int> _out;
//	unordered_set<int> _set;
//
//	for (int i = 0; i < coins.size(); i++)
//	{
//		if (coins[i] == amount) return 1;
//		if (coins[i] > amount) continue;
//		_in.push_back(coins[i]);
//		_set.insert(coins[i]);
//	}
//	int k = 2;
//	while (!_in.empty())
//	{
//		bool bOverFlag = true;
//		for (auto &a : _in)
//		{
//			for (auto &c : coins)
//			{
//				if (a + c == amount) return k;
//				if (a + c > amount)
//				{
//					if (bOverFlag) return -1;
//					continue;
//				}
//				bOverFlag = false;
//				if (_set.count(a + c)) continue;
//				_out.push_back(a + c);
//				_set.insert(a + c);
//			}
//		}
//		k++;
//		_in.swap(_out);
//		_out.clear();
//	}
//	return -1;
//}

//////////////////////////////////////////////////////////////////////////
void coinChange(vector<int>& coins, int amount, int c_index, int count, int &ans)
{
	if (amount == 0)
	{
		ans = min(ans, count);
		return;
	}
	if (c_index == coins.size()) return;

	for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)
	{
		coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
	}
	return;
}

int coinChange(vector<int>& coins, int amount)
{
	if (amount == 0) return 0;
	sort(coins.rbegin(), coins.rend());
	int ans = INT_MAX;
	coinChange(coins, amount, 0, 0, ans);
	return ans == INT_MAX ? -1 : ans;
}

int main()
{
	vector<vector<int>> TESTS;
	vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back({ 1,2,5 });
	K.push_back(11);
	ANSWERS.push_back(3);

	TESTS.push_back({ 2 });
	K.push_back(3);
	ANSWERS.push_back(-1);

	TESTS.push_back({ 2 });
	K.push_back(1);
	ANSWERS.push_back(-1);

	TESTS.push_back({ 1 });
	K.push_back(0);
	ANSWERS.push_back(0);

	TESTS.push_back({ 186,419,83,408 });
	K.push_back(6249);
	ANSWERS.push_back(20);

	TESTS.push_back({ 3,7,405,436 });
	K.push_back(8839);
	ANSWERS.push_back(25);

	TESTS.push_back({ 71,440,63,321,461,310,467,456,361 });
	K.push_back(9298);
	ANSWERS.push_back(20);

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = coinChange(TESTS[i], K[i]);
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


