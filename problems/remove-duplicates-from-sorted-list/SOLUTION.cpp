
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
	{
		ListNode* pRet = head;
		ListNode* pNode = head;
		while (pNode != nullptr && pNode->next != nullptr)
		{
			if (pNode->val == pNode->next->val)
			{
				pNode->next = pNode->next->next;
			}
			else
			{
                pNode = pNode->next;
			}
		}
		return pRet;
    }
};

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.deleteDuplicates(head);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
