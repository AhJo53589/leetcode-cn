
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

#define USE_SOLUTION_CUSTOM
//Node* _solution_custom(TestCases& tc)
string _solution_custom(TestCases& tc)
{
	vector<unordered_map<string, string>> input = StringToVectorMapStringString(tc.get<string>());
	for (auto um : input)
	{
		for (auto s : um)
		{
			cout << "[" << s.first << "] = " << s.second << ",\t";
		}
		cout << endl;
	}

	unordered_map<string, Node*> nodes;
	nodes["null"] = nullptr;
	for (auto um : input)
	{
		string id = um["$id"];
		int val = stoi(um["val"]);
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

	Node* ans = connect(nodes["1"]);

	return "";
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

