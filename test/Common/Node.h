#ifndef NODE_H
#define NODE_H

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;


#ifndef NODE_DEFINE_EXCULDE_DEFAULT
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

string NodeToString(const Node* pHead);
Node* StringToNode(const string data);

#endif 



#endif //NODE_H
