// Node.cpp 


//////////////////////////////////////////////////////////////////////////
#ifdef NODE_DEFINE_LEETCODE_133_CLONE_GRAPH
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
#endif

//////////////////////////////////////////////////////////////////////////
#ifdef NODE_DEFINE_LEETCODE_138_COPY_LIST_WITH_RANDOM_POINTER
class Node
{
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random)
	{
		val = _val;
		next = _next;
		random = _random;
	}
};

Node* StringToNode(const string data)
{
	vector<vector<string>> val = StringToVectorVectorString(data);
	vector<Node*> nodes(val.size(), nullptr);
	for (auto& n : nodes)
	{
		n = new Node(0, nullptr, nullptr);
	}
	for (size_t i = 0; i < val.size(); i++)
	{
		nodes[i]->val = stoi(val[i][0]);
		nodes[i]->next = (i == val.size() - 1) ? nullptr : nodes[i + 1];
		nodes[i]->random = (val[i][1] == "null") ? nullptr : nodes[stoi(val[i][1])];
	}
	return nodes.empty() ? nullptr : nodes[0];
}

string NodeToString(const Node* pHead)
{
	unordered_map<const Node*, int> node_id;
	vector<const Node*> id_node;

	int idx = 0;
	while (pHead != nullptr)
	{
		id_node.push_back(pHead);
		node_id[pHead] = idx++;
		pHead = pHead->next;
	}

	vector<vector<string>> val(id_node.size(), vector<string>(2));
	for (size_t i = 0; i < val.size(); i++)
	{
		val[i][0] = to_string(id_node[i]->val);
		val[i][1] = (id_node[i]->random == nullptr) ? "null" : to_string(node_id[id_node[i]->random]);
	}

	string ret = VectorVectorStringToString(val, false);
	return ret;
}
#endif

//////////////////////////////////////////////////////////////////////////
#ifdef NODE_DEFINE_LEETCODE_430_FLATTEN_A_MULTILEVEL_DOUBLY_LINKED_LIST
class Node
{
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;

	Node() {}

	Node(int _val, Node* _prev, Node* _next, Node* _child)
	{
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};

Node* StringToNode(const string data)
{
	vector<string> vs = StringToVectorString(data);

	vector<vector<Node*>> nodes;

	size_t idx = 0;
	size_t space = 0;
	bool newLine = true;
	while (idx < vs.size())
	{
		if (vs[idx] == "null")
		{
			if (!newLine)
			{
				nodes.back().push_back(nullptr);
			}
			space += newLine;
			newLine = true;
		}
		else
		{
			if (newLine)
			{
				nodes.push_back(vector<Node*>());
				for (size_t t = 0; t < space; t++)
				{
					nodes.back().push_back(nullptr);
				}
				newLine = false;
			}

			nodes.back().push_back(new Node(stoi(vs[idx]), nullptr, nullptr, nullptr));
		}
		idx++;
	}

	for (size_t i = 0; i < nodes.size(); i++)
	{
		newLine = true;
		for (size_t j = 0; j < nodes[i].size() - 1; j++)
		{
			if (nodes[i][j] == nullptr) continue;
			if (newLine)
			{
				newLine = false;
				if (i != 0)
				{
					nodes[i - 1][j]->child = nodes[i][j];
				}
			}
			nodes[i][j]->next = nodes[i][j + 1];
			if (nodes[i][j + 1] != nullptr)
			{
				nodes[i][j + 1]->prev = nodes[i][j];
			}
		}
	}

	return nodes.empty() ? nullptr : nodes[0][0];
}

string NodeToString(const Node* pHead)
{
	vector<string> val;
	const Node* cur = pHead;
	const Node* lv_head = pHead;

	while (true)
	{
		while (cur != nullptr)
		{
			val.push_back(to_string(cur->val));
			cur = cur->next;
		}
		val.push_back("null");
		while (lv_head != nullptr && lv_head->child == nullptr)
		{
			val.push_back("null");
			lv_head = lv_head->next;
		}
		if (lv_head == nullptr) break;
		lv_head = lv_head->child;
		cur = lv_head;
	}

	while (val.back() == "null")
	{
		val.pop_back();
	}
	val.push_back("null");

	string ret = VectorStringToString(val, false);
	return ret;
}
#endif