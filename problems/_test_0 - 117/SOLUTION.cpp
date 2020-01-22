


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
//Node* connect(Node* root) {
//	if (root == NULL)
//		return NULL;
//
//	Node *dummy = new Node(-1, NULL, NULL, NULL);
//	Node *pre = dummy;
//	Node *head = root;
//
//	while (root != NULL) {
//		if (root->left) {
//			pre->next = root->left;
//			pre = pre->next;
//		}
//
//		if (root->right) {
//			pre->next = root->right;
//			pre = pre->next;
//		}
//
//		root = root->next;
//
//		if (root == NULL) {
//			pre = dummy;
//			root = dummy->next;
//			dummy->next = NULL;
//		}
//	}
//
//	return head;
//}

//////////////////////////////////////////////////////////////////////////
Node* connect(Node* root)
{
	if (root == nullptr) return {};

	if (root->left != nullptr && root->right != nullptr) root->left->next = root->right;

	auto f = [root]()
	{
		Node* pNode = root->next;
		while (pNode != nullptr)
		{
			if (pNode->left != nullptr) return pNode->left;
			if (pNode->right != nullptr) return pNode->right;
			pNode = pNode->next;
		}
		return pNode;
	};
	Node* pNodeChild = (root->right == nullptr) ? root->left : root->right;
	Node* pNodeNextChild = f();

	if (pNodeChild != nullptr && pNodeNextChild != nullptr) pNodeChild->next = pNodeNextChild;

	connect(root->right);
	connect(root->left);
	return root;
}

//////////////////////////////////////////////////////////////////////////
//Node* _solution_run(Node* root)
//{
//	return connect(root);
//}

Node* StringToNode(string data)
{
	if (data.empty()) return nullptr;
	if (data[0] == '[') data = data.substr(1, data.size() - 2);
	vector<string> splitData = split(data, ",");
	if (data == "" || splitData[0] == "null") return nullptr;

	Node* root = new Node(stoi(splitData[0].c_str()), nullptr, nullptr, nullptr);
	queue<Node*> qTree;
	qTree.push(root);

	int i = 1;
	while (!qTree.empty())
	{
		Node* qHead = nullptr;
		while (qHead == nullptr)
		{
			if (qTree.empty()) return root;
			qHead = qTree.front();
			qTree.pop();
		}

		auto f = [&qTree](string& s, Node** p)
		{
			while (s.front() == ' ') s = s.substr(1, s.size() - 1);
			while (s.back() == ' ') s.pop_back();
			if (s == "null")
			{
				qTree.push(nullptr);
			}
			else
			{
				*p = new Node(stoi(s.c_str()), nullptr, nullptr, nullptr);
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

string NodeLevelOrderToString(Node* root)
{
	string str = "[";
	
	while (root != nullptr)
	{
		Node* cur = root;
		root = nullptr;
		while (cur != nullptr)
		{
			if (root == nullptr)
			{
				root = (cur->left != nullptr) ? cur->left : cur->right;
			}

			str += to_string(cur->val);
			str += ",";
			cur = cur->next;
		}
		str += "#,";
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
	str += "]";
	return str;
}

#define USE_SOLUTION_CUSTOM
//Node* _solution_custom(TestCases& tc)
string _solution_custom(TestCases& tc)
{
	Node* root = StringToNode(tc.get<string>());
	Node* ret = connect(root);
	string ans = NodeLevelOrderToString(ret);
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

