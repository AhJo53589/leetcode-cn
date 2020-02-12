#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>


struct TreeNode;


TreeNode *StringToTreeNode(std::string data);
std::string TreeNodeToString(const TreeNode *root);
std::string TreeNodeToString_Full(const TreeNode *root);
std::vector<int> GetOffsetForDraw(int _size);
void DrawTreeNode(const TreeNode *root);

TreeNode *FindTreeNode(TreeNode *root, int val);



struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

	friend std::ostream & operator<<(std::ostream& os, const TreeNode *p)
	{
		std::string s = TreeNodeToString(p);
		os << s.c_str();
		return os;
	}
	friend void operator>>(std::string &s, TreeNode **rhs)
	{
		*rhs = StringToTreeNode(s);
	}
};



#endif //TREE_NODE_H
