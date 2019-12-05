


//////////////////////////////////////////////////////////////////////////
ListNode* mergeKLists(vector<ListNode*>& lists)
{

	ListNode *pHead = new ListNode(0);
	ListNode *pNode = pHead;
	int len = lists.size();
	int nullCount = 0;
	while (nullCount < len)
	{
		nullCount = 0;
		pair<int, int> minVal = { -1, INT_MAX };
		for (int i = 0; i < lists.size(); i++)
		{
			if (lists[i] == nullptr)
			{
				nullCount++;
				continue;
			}
			if (lists[i]->val < minVal.second)
			{
				minVal.first = i;
				minVal.second = lists[i]->val;
			}
		}
		if (minVal.first == -1) continue;
		pNode->next = lists[minVal.first];
		pNode = pNode->next;
		lists[minVal.first] = lists[minVal.first]->next;
	}
	pNode->next = nullptr;
	pNode = pHead->next;
	delete pHead;
	return pNode;
}

//////////////////////////////////////////////////////////////////////////
//ListNode* _solution_run(vector<ListNode*>& lists)
//{
//	return mergeKLists(lists);
//}

#define USE_SOLUTION_CUSTOM
ListNode* _solution_custom(TestCases &tc)
{
	vector<vector<int>> vv = tc.get<vector<vector<int>>>();
	vector<ListNode*> vl;
	for (auto s : vv)
	{
		string temp = VectorIntToString(s);
		vl.push_back(StringToListNode(temp));
	}
	return mergeKLists(vl);
}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/merge-k-sorted-lists/tests.txt";
}

