
#define NODE_DEFINE_LEETCODE_430_FLATTEN_A_MULTILEVEL_DOUBLY_LINKED_LIST
#include "../../test/Common/Node.cpp"

/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;
};
*/


//////////////////////////////////////////////////////////////////////////
Node* flatten(Node* head)
{
	Node* pNode = head;
	while (pNode != NULL)
	{
		if (pNode->child != NULL)
		{
			Node* pNext = pNode->next;
			pNode->next = pNode->child;
			pNode->next->prev = pNode;
			pNode->child = NULL;
			flatten(pNode);
			while (pNode != NULL && pNode->next != NULL) pNode = pNode->next;
			pNode->next = pNext;
			if (pNext != NULL) pNext->prev = pNode;
		}
		pNode = pNode->next;
	}
	return head;
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
	Node* ret = flatten(root);
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
	return "../../problems/_test_0/tests.txt";
}

