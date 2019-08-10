// 173.binary-search-tree-iterator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		if (root != nullptr) stk.push(root);
		while (!stk.empty() && stk.top()->left != nullptr) stk.push(stk.top()->left);
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *pNode = stk.top();
		stk.pop();
		int res = pNode->val;
		if (pNode->right != nullptr)
		{
			stk.push(pNode->right);
			while (stk.top()->left != nullptr) stk.push(stk.top()->left);
		}
		return res;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !stk.empty();
	}

private:
	stack<TreeNode *> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


int main()
{
	vector<TreeNode *> N;
	vector<string> A;

	A.push_back("7,3,15,null,null,9,20");
	N.push_back(StringToTreeNode(A.back()));

	A.push_back("");
	N.push_back(StringToTreeNode(A.back()));

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "///////////////////////////////////////" << endl;
		cout << N[i] << endl;
		DrawTreeNode(N[i]);

		BSTIterator* obj = new BSTIterator(N[i]);
		if (obj == nullptr) continue;
		cout << "BSTIterator = " << endl;
		while (obj->hasNext()) cout << obj->next() << ",";
		cout << endl;
		delete obj;
	}
}