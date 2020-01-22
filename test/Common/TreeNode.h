#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;


struct TreeNode;


TreeNode *StringToTreeNode(const string data);
string TreeNodeToString(const TreeNode *root);
string TreeNodeToString_Full(const TreeNode *root);
vector<int> GetOffsetForDraw(int _size);
void DrawTreeNode(const TreeNode *root);

TreeNode *FindTreeNode(TreeNode *root, int val);



struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

	friend ostream & operator<<(ostream& os, const TreeNode *p)
	{
		string s = TreeNodeToString(p);
		os << s.c_str();
		return os;
	}
	friend void operator>>(string &s, TreeNode **rhs)
	{
		*rhs = StringToTreeNode(s);
	}
};



#endif //TREE_NODE_H
