
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
	while (pNode != nullptr)
	{
		if (pNode->child != nullptr)
		{
			Node* pNext = pNode->next;
			pNode->next = pNode->child;
			pNode->next->prev = pNode;
			pNode->child = nullptr;
			flatten(pNode);
			while (pNode != nullptr && pNode->next != nullptr)
			{
				pNode = pNode->next;
			}
			pNode->next = pNext;
			if (pNext != nullptr)
			{
				pNext->prev = pNode;
			}
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
	return "../../problems/flatten-a-multilevel-doubly-linked-list/tests.txt";
}

