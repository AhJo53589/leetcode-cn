


//////////////////////////////////////////////////////////////////////////
void deleteNode(ListNode *node)
{
	ListNode *pNext = node->next;
	node->val = pNext->val;
	node->next = pNext->next;
	delete(pNext);
	pNext = nullptr;
}

//////////////////////////////////////////////////////////////////////////
void _solution_run(ListNode *node)
{
	deleteNode(node);
}

#define USE_SOLUTION_CUSTOM
ListNode* _solution_custom(TestCases &tc)
{
	ListNode* pHead(tc.get<ListNode*>());
	deleteNode(FindNodeByVal(pHead, tc.get<int>()));
	return pHead;
}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/delete-node-in-a-linked-list/tests.txt";
}

