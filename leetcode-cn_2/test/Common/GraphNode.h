#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Node
{
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors)
	{
		val = _val;
		neighbors = _neighbors;
	}
};

//void initNode(Node **root, string strInitData);
//void printNode(Node *root);



#endif //GRAPH_NODE_H
