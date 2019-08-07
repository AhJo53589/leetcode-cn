// 102.binary-tree-level-order-traversal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;



//////////////////////////////////////////////////////////////////////////
vector<vector<int>> levelOrder(TreeNode* root)
{
	if (root == nullptr) return {};
	vector<vector<int>> ans;
	queue<TreeNode *> que[2];
	int seq = 0;

	que[seq].push(root);
	while (!(que[0].empty() && que[1].empty()))
	{
		int seq_next = (seq + 1) % 2;
		vector<int> num;
		while (!que[seq].empty())
		{
			TreeNode *pNode = que[seq].front();
			que[seq].pop();
			num.push_back(pNode->val);

			if (pNode->left != nullptr) que[seq_next].push(pNode->left);
			if (pNode->right != nullptr) que[seq_next].push(pNode->right);
		}
		ans.push_back(num);
		seq = seq_next;
	}
	return ans;
}

int main()
{
	vector<TreeNode *> N;
	vector<vector<vector<int>>> A;
	TreeNode *pHead = nullptr;

	StringToTreeNode(&pHead, "3,9,20,null,null,15,7");
	N.push_back(pHead);
	A.push_back({ {3}, { 9,20 }, { 15,7 } });
	pHead = nullptr;


	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "///////////////////////////////////////" << endl;
		printTreeNode(N[i]);
		cout << "levelOrder = " << endl;
		printVectorVectorInt(A[i]);
		vector<vector<int>> ans = levelOrder(N[i]);
		cout << "my answer = " << endl;
		printVectorVectorInt(ans);
	}
}