// 103.binary-tree-zigzag-level-order-traversal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	if (root == nullptr) return {};
	vector<vector<int>> ans;
	stack<TreeNode *> stk[2];
	int seq = 0;

	stk[seq].push(root);
	while (!(stk[0].empty() && stk[1].empty()))
	{
		int seq_next = (seq + 1) % 2;
		vector<int> num;
		while (!stk[seq].empty())
		{
			TreeNode *pNode = stk[seq].top();
			stk[seq].pop();
			num.push_back(pNode->val);

			if (seq == 0)
			{
				if (pNode->left != nullptr) stk[seq_next].push(pNode->left);
				if (pNode->right != nullptr) stk[seq_next].push(pNode->right);
			}
			else
			{
				if (pNode->right != nullptr) stk[seq_next].push(pNode->right);
				if (pNode->left != nullptr) stk[seq_next].push(pNode->left);
			}
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
	A.push_back({ {3}, { 20,9 }, { 15,7 } });
	pHead = nullptr;


	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "///////////////////////////////////////" << endl;
		printTreeNode(N[i]);
		cout << "zigzagLevelOrder = " << endl;
		printVectorVectorInt(A[i]);
		vector<vector<int>> ans = zigzagLevelOrder(N[i]);
		cout << "my answer = " << endl;
		printVectorVectorInt(ans);
	}
}