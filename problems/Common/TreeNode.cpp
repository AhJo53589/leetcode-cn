// TreeNode.cpp 
//

//#include "pch.h"

#include <iostream>

#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

#include "Common.h"
#include "TreeNode.h"
using namespace std;


TreeNode * StringToTreeNode(string data)
{
	if (data.empty()) return nullptr;
	if (data[0] == '[') data = data.substr(1, data.size() - 2);
	vector<string> splitData = split(data, ",");
	if (data == "" || splitData[0] == "null") return nullptr;

	TreeNode *root = new TreeNode(stoi(splitData[0].c_str()));
	queue<TreeNode *> qTree;
	qTree.push(root);

	int i = 1;
	while (!qTree.empty())
	{
		TreeNode *qHead = nullptr;
		while (qHead == nullptr)
		{
			if (qTree.empty()) return root;
			qHead = qTree.front();
			qTree.pop();
		}

		auto f = [&qTree](string &s, TreeNode **p)
		{
			while (s.front() == ' ') s = s.substr(1, s.size() - 1);
			while (s.back() == ' ') s.pop_back();
			if (s == "null")
			{
				qTree.push(nullptr);
			}
			else
			{
				*p = new TreeNode(stoi(s.c_str()));
				qTree.push(*p);
			}
		};

		if (i == splitData.size()) return root;
		f(splitData[i], &qHead->left);
		i++;

		if (i == splitData.size()) return root;
		f(splitData[i], &qHead->right);
		i++;
	}
	return root;
}

string TreeNodeToString(const TreeNode * root)
{
	string str;
	queue<const TreeNode *> qTree;
	qTree.push(root);

	while (!qTree.empty())
	{
		const TreeNode *qHead = qTree.front();
		qTree.pop();

		if (qHead == nullptr)
		{
			str += "null,";
			continue;
		}
		str += to_string(qHead->val);
		str += ",";
		qTree.push(qHead->left);
		qTree.push(qHead->right);
	}
	int len = str.size();
	while (true)
	{
		if (len > 1 && str.back() == ',') len -= 1;
		else break;
		if (len > 4 && str.substr(len - 4, 4) == "null") len -= 4;
		else break;
	}
	str = str.substr(0, len);
	return str;
}

string TreeNodeToString_Full(const TreeNode * root)
{
	vector<vector<string>> value_buffer;
	queue<const TreeNode *> que[2];

	int seq = 0;
	que[seq].push(root);
	while (!(que[0].empty() && que[1].empty()))
	{
		int seq_next = (seq + 1) % 2;
		bool nullpter_flag = true;
		vector<string> buf;
		while (!que[seq].empty())
		{
			const TreeNode *pNode = que[seq].front();
			que[seq].pop();

			if (pNode == nullptr)
			{
				que[seq_next].push(nullptr);
				que[seq_next].push(nullptr);
				buf.push_back("null");
			}
			else
			{
				nullpter_flag = false;
				buf.push_back(to_string(pNode->val));
				que[seq_next].push(pNode->left);
				que[seq_next].push(pNode->right);
			}
		}
		if (nullpter_flag) break;
		value_buffer.push_back(buf);
		seq = seq_next;
	}

	string str;
	for (auto &m : value_buffer) for (auto &n : m) str += n + ",";
	if (!str.empty() && str.back() == ',') str.pop_back();
	return str;
}

vector<int> GetOffsetForDraw(int _size)
{
	int len_y = log(_size) / log(2) + 1;
	int _size_full = pow(2, len_y);
	vector<int> pos(_size_full, 0);
	int s = _size_full;
	for (int i = s / 2; i < s; i++)
	{
		pos[i] = (i - s / 2) * 2;
	}
	s /= 2;
	while (s > 0)
	{
		for (int i = s / 2; i < s; i++)
		{
			pos[i] = pos[i * 2] + (pos[i * 2 + 1] - pos[i * 2]) / 2;
		}
		s /= 2;
	}
	for (size_t i = 0; i < pos.size() - 1; i++)
	{
		pos[i] = pos[i + 1];
	}
	pos.pop_back();
	return pos;
}

void DrawTreeNode(const TreeNode *root)
{
	if (root == nullptr) return;
	string str = TreeNodeToString_Full(root);
	vector<string> splitData = split(str, ",");

	string strVal;
	int x = 0;
	int y = 1;
	vector<int> pos = GetOffsetForDraw(splitData.size());
	for (int i = 0; i < splitData.size(); i++)
	{
		while (x < pos[i])
		{
			x++;
			cout << " ";
			strVal += " ";
		}
		if (splitData[i] != "null")
		{
			if (i != 0 && i % 2 == 0) cout << "\\";
			if (i != 0 && i % 2 == 1) cout << "/";
			int val_x = splitData[i].size() - 1;
			while (val_x-- > 0) cout << " ";
			strVal += splitData[i];
		}
		
		if (i == pow(2, y) - 1 - 1)
		{
			x = 0;
			y++;
			cout << endl << strVal << endl;
			strVal.clear();
		}
	}
	cout << endl;
}

TreeNode * FindTreeNode(TreeNode * root, int val)
{
	queue<TreeNode *> qTree;
	qTree.push(root);

	while (!qTree.empty())
	{
		TreeNode *qHead = qTree.front();
		qTree.pop();
		if (qHead == nullptr) continue;
		if (qHead->val == val) return qHead;
		qTree.push(qHead->left);
		qTree.push(qHead->right);
	}
	return nullptr;
}

