
#define NODE_DEFINE_LEETCODE_117_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II
#include "../../test/Common/Node.cpp"

/*
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
*/


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

#define USE_SOLUTION_CUSTOM
//Node* _solution_custom(TestCases& tc)
string _solution_custom(TestCases& tc)
{
	Node* root = StringToNode(tc.get<string>());
	Node* ret = connect(root);
	string ans = NodeToString(ret);
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
	return "../../problems/populating-next-right-pointers-in-each-node-ii/tests.txt";
}

