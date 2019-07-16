// 652.find-duplicate-subtrees.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
unordered_map<string, TreeNode *> m;
unordered_set<string> s;
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
{
	vector<TreeNode *> treeList;
	if (root == NULL) return treeList;

	string str = TreeNodeToString(root);
	if (!m.count(str)) m[str] = root;
	else if (!s.count(str))
	{
		s.insert(str);
		treeList.push_back(root);
	}

	vector<TreeNode *> left = findDuplicateSubtrees(root->left);
	treeList.insert(treeList.end(), left.begin(), left.end());
	vector<TreeNode *> right = findDuplicateSubtrees(root->right);
	treeList.insert(treeList.end(), right.begin(), right.end());

	return treeList;
}

int main()
{
	TreeNode *pRoot = NULL;
	StringToTreeNode(&pRoot, "1,2,3,4,null,2,4,null,null,4,null,null,null");

	vector<TreeNode *> treelist = findDuplicateSubtrees(pRoot);
	for (auto t : treelist)
	{
		printTreeNode(t);
		cout << endl;
	}
}
