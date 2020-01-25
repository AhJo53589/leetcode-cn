
#define NODE_DEFINE_LEETCODE_138_COPY_LIST_WITH_RANDOM_POINTER
#include "../../test/Common/Node.cpp"

/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
*/


//////////////////////////////////////////////////////////////////////////
Node* copyRandomList(Node* head)
{
	map<Node*, Node*> visited;
	visited[NULL] = NULL;

	Node* pPrev = NULL;
	Node* pNode = head;
	while (pNode != NULL)
	{
		Node* pNew = new Node();
		visited[pNode] = pNew;
		pNode = pNode->next;
	}
	pNode = head;
	while (pNode != NULL)
	{
		Node* pNew = visited[pNode];
		pNew->val = pNode->val;
		pNew->random = visited[pNode->random];
		pNew->next = NULL;
		if (pPrev != NULL)
		{
			visited[pPrev]->next = pNew;
		}
		pPrev = pNode;
		pNode = pNode->next;
	}
	return visited[head];
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
	Node* ret = copyRandomList(root);
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
	return "../../problems/copy-list-with-random-pointer/tests.txt";
}

