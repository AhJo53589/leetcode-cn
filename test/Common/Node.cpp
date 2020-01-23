// GraphNode.cpp 
//

//#include "pch.h"

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

#include "Common.h"
#include "Node.h"
using namespace std;

#ifndef NODE_DEFINE_EXCULDE_DEFAULT
string NodeToString(const Node* pHead)
{
	unordered_map<const Node*, int> node_id;
	vector<const Node*> id_node;
	stack<const Node*> st;
	st.push(pHead);
	
	size_t i = 0;
	while (!st.empty())
	{
		auto q = st.top();
		st.pop();

		if (node_id.find(q) != node_id.end()) continue;
		node_id[q] = ++i;
		id_node.push_back(q);
		for (size_t j = q->neighbors.size() - 1; j < q->neighbors.size(); j--)
		{
			st.push(q->neighbors[j]);
		}
	}
	
	vector<vector<int>> val;
	for (auto& n : id_node)
	{
		vector<int> temp;
		for (auto& nei : n->neighbors)
		{
			temp.push_back(node_id[nei]);
		}
		val.push_back(temp);
	}

	string ret = VectorVectorIntToString(val);
	return ret;
}

Node* StringToNode(const string data)
{
	vector<vector<int>> val = StringToVectorVectorInt(data);
	vector<Node*> nodes(val.size(), nullptr);
	int v = 0;
	for (auto& n : nodes)
	{
		n = new Node(++v, vector<Node*>());
	}
	for (size_t i = 0; i < val.size(); i++)
	{
		for (size_t j = 0; j < val[i].size(); j++)
		{
			nodes[i]->neighbors.push_back(nodes[val[i][j] - 1]);
		}
	}
	return nodes[0];
}
#endif