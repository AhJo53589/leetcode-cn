// 133.CloneGraph.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>

#include "..\Common\GraphNode.h"

using namespace std;


//Node* cloneGraph(Node* node) {
//	unordered_map<Node*, Node*> toCopy;
//	return clone(node, toCopy);
//}
//Node* clone(Node* root, unordered_map<Node*, Node*>& toCopy) {
//	if (toCopy.find(root) != toCopy.end()) return toCopy[root];
//	Node* res = new Node(root->val, vector<Node*>({}));
//	toCopy.insert({ root, res });
//	for (Node* p : root->neighbors)
//		res->neighbors.push_back(clone(p, toCopy));
//	return res;
//}


/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
*/
Node* cloneGraph(Node* node)
{
	if (node == NULL) return NULL;

	map<Node *, Node *> visited;
	stack<Node *> s;

	s.push(node);
	while (!s.empty())
	{
		Node *cur = s.top();
		s.pop();
		if (visited.count(cur) == 0)
		{
			Node *pNew = new Node();
			visited[cur] = pNew;
			for (auto n : cur->neighbors)
			{
				s.push(n);
			}
		}
	}

	for (auto i = visited.begin(); i != visited.end(); i++)
	{
		(i->second)->val = (i->first)->val;
		for (auto n : (i->first)->neighbors)
		{
			(i->second)->neighbors.push_back(visited[n]);
		}
	}

	return visited[node];
}

void init(Node **root)
{
	Node *pNode1 = new Node();
	Node *pNode2 = new Node();
	Node *pNode3 = new Node();
	Node *pNode4 = new Node();

	pNode1->val = 1;
	pNode2->val = 2;
	pNode3->val = 3;
	pNode4->val = 4;

	pNode1->neighbors.push_back(pNode2);
	pNode1->neighbors.push_back(pNode4);

	pNode2->neighbors.push_back(pNode1);
	pNode2->neighbors.push_back(pNode3);

	pNode3->neighbors.push_back(pNode2);
	pNode3->neighbors.push_back(pNode4);

	pNode4->neighbors.push_back(pNode1);
	pNode4->neighbors.push_back(pNode3);

	*root = pNode1;
}

void printNode(Node *root)
{
	if (root == NULL) return;

	set<Node *> visited;
	stack<Node *> s;

	s.push(root);
	while (!s.empty())
	{
		Node *cur = s.top();
		s.pop();
		if (visited.count(cur) == 0)
		{
			visited.insert(cur);
			for (auto n : cur->neighbors)
			{
				s.push(n);
			}
		}
	}

	int _id = 1;
	map<Node*, int> mapNode;
	for (auto n : visited)
	{
		mapNode[n] = _id;
		_id++;
	}

	for (auto _visitedNode : visited)
	{
		cout << "id = " << mapNode[_visitedNode] << " | ";
		cout << "val = " << _visitedNode->val << " | ";
		cout << "neighbors = [ | ";
		for (auto _neighborsNode : _visitedNode->neighbors)
		{
			cout << "id = " << mapNode[_neighborsNode] << " | ";
			cout << "val = " << _neighborsNode->val << " | ";
		}
		cout << "]" << endl;
	}
}

int main()
{
	Node *root = NULL;

	cout << "init = " << endl;
	init(&root);
	printNode(root);

	cout << endl << "clone = " << endl;
	Node *clone = cloneGraph(root);
	printNode(clone);
}
