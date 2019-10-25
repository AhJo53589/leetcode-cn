// 107.binary-tree-level-order-traversal-ii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <functional>

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
#include <sstream>

#include "..\Common\Common.h"
#include "..\Common\TreeNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
void levelOrderBottom(queue<TreeNode *> que, vector<vector<int>> &ans)
{
	if (que.empty()) return;
	queue<TreeNode *> queNext;
	vector<int> vec;
	while (!que.empty())
	{
		TreeNode *pNode = que.front();
		que.pop();
		vec.push_back(pNode->val);
		if (pNode->left != nullptr) queNext.push(pNode->left);
		if (pNode->right != nullptr) queNext.push(pNode->right);
	}
	levelOrderBottom(queNext, ans);
	ans.push_back(vec);
}

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	vector<vector<int>> ans;
	queue<TreeNode *> q;
	if (root != nullptr) q.push(root);
	levelOrderBottom(q, ans);
	return ans;
}


int main()
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);

	auto f_time_begin = [&time, &nFreq, &nBeginTime, &nEndTime]()
	{
		cout << endl << "/////////////////////////////" << endl;
		QueryPerformanceCounter(&nBeginTime);
	};

	auto f_time_end = [&time, &nFreq, &nBeginTime, &nEndTime]()
	{
		QueryPerformanceCounter(&nEndTime);
		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		cout << "////////////////////////////////////////////////////////// time: " << time * 1000 << "ms" << endl;
	};

	//////////////////////////////////////////////////////////////////////////
	vector<TreeNode*> TESTS;
	vector<vector<vector<int>>> ANSWERS;

	TESTS.push_back(StringToTreeNode("[3,9,20,null,null,15,7]"));
	ANSWERS.push_back({ {15,7},{9,20},{3} });


	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		auto ans = levelOrderBottom(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		f_time_end();
	}
}