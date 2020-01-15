
// Definition for a Node.
class Node 
{
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

//////////////////////////////////////////////////////////////////////////
Node* connect(Node* root)
{
	if (root == nullptr) return {};

	if (root->left != nullptr && root->right != nullptr) root->left->next = root->right;
	if (root->next != nullptr && root->next->left != nullptr) root->right->next = root->next->left;

	connect(root->left);
	connect(root->right);
	return root;
}

//////////////////////////////////////////////////////////////////////////
Node* _solution_run(Node* root)
{
	return connect(root);
}

void preorder(Node* node, int& id, map<string, Node*>& nodes, map<Node*, string>& n_s)
{
	auto getNextId = [&id]()
	{ return "\"" + to_string(id++) + "\""; };

	if (node == nullptr) return;
	if (n_s.count(node) != 0) return;
	string s = getNextId();
	nodes[s] = node;
	n_s[node] = s;
	preorder(node->left, id, nodes, n_s);
	preorder(node->right, id, nodes, n_s);
	preorder(node->next, id, nodes, n_s);
}

#define USE_SOLUTION_CUSTOM
//Node* _solution_custom(TestCases& tc)
string _solution_custom(TestCases& tc)
{
	// string to map_string
	vector<map<string, string>> input = StringToVectorMapStringString(tc.get<string>());
	for (auto um : input)
	{
		for (auto s : um)
		{
			cout << "[" << s.first << "] = " << s.second << ",\t";
		}
		cout << endl;
	}

	// map_string to map_nodes
	map<string, Node*> nodes;
	nodes["null"] = nullptr;
	for (auto um : input)
	{
		string id = um["$id"];
		int val = um.count("val") ? stoi(um["val"]) : 0;
		Node* newNode = new Node(val, nullptr, nullptr, nullptr);
		nodes[id] = newNode;
	}
	for (auto um : input)
	{
		string id = um["$id"];
		nodes[id]->left = nodes[um["left"]];
		nodes[id]->right = nodes[um["right"]];
		nodes[id]->next = nodes[um["next"]];
	}

	// run
	Node* nd = connect(nodes["\"1\""]);

	// nodes to map_nodes
	map<string, Node*> nodes2;
	map<Node*, string> n_s;
	n_s[nullptr] = "null";
	int id = 1;
	preorder(nd, id, nodes2, n_s);

	// map_nodes to map_string
	vector<map<string, string>> output;
	for (auto n : nodes2)
	{
		Node* cur = n.second;
		map<string, string> _m;
		_m["$id"] = n.first;
		_m["left"] = n_s[cur->left];
		_m["right"] = n_s[cur->right];
		_m["next"] = n_s[cur->next];
		_m["val"] = to_string(cur->val);
		output.push_back(_m);
	}

	// map_string to string
	string ans = VectorMapStringStringToString(output);
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/_test_0/tests.txt";
}

