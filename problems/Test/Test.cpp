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
#include <set>
#include <stack>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
#include "..\Common\TreeNode.h"
#include "..\Common\ListNode.h"
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

vector<TreeNode*> generateTrees(int n) 
{
	vector<TreeNode *> treeList;
	TreeNode *pTree = new TreeNode(1);
	treeList.push_back(pTree);
	if (n == 1) return treeList;
}


int main()
{
	vector<TreeNode *> tree = generateTrees(1);
	for (auto t : tree)
	{
		printTreeNode(t);
	}
}
