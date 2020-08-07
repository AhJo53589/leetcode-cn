
//////////////////////////////////////////////////////////////////////////
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int a = 0;
        int b = 0;
        ListNode* p = headA;
        while (p != nullptr) {
            p = p->next;
            a++;
        }
        p = headB;
        while (p != nullptr) {
            p = p->next;
            b++;
        }

        int len = max(a, b);
        for (int i = 0; i < len; i++) {
            int ia = i - (len - a);
            int ib = i - (len - b);
            if (ia >= 0 && ib >= 0) {
                if (headA == headB) return headA;
            }
            if (ia >= 0) {
                headA = headA->next;
            }
            if (ib >= 0) {
                headB = headB->next;
            }
        }
        return nullptr;
    }
};

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* headA, ListNode* headB)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.getIntersectionNode(headA, headB);
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
