#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;


struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode_Val
{
	int val;
	bool isNull;
	TreeNode_Val(int x) : val(x), isNull(false) {}
	TreeNode_Val(bool isN) : val(0), isNull(isN) {}
};

void StringToTreeNode(TreeNode **root, string strInitData);
void printTreeNode(TreeNode *root);



#endif //TREE_NODE_H
