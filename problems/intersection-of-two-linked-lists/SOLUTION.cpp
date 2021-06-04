


//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA);
        int lenB = getLen(headB);
        if (lenA < lenB) {
            swap(lenA, lenB);
            swap(headA, headB);
        }
        
        for (int i = 0; i < lenA - lenB; i++) {
            headA = headA->next;
        }

        while (headA != nullptr) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }

    int getLen(ListNode* head) {
        int len = 0;
        while (head != nullptr) {
            len++;
            head = head->next;
        }
        return len;
    }
};

//////////////////////////////////////////////////////////////////////////
//ListNode _solution_run(ListNode *headA, ListNode *headB)
//{
//	return *getIntersectionNode(headA,headB);
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	string l1 = tc.get<string>();
	string l2 = tc.get<string>();
	int k1 = tc.get<int>();
	int k2 = tc.get<int>();
	ListNode *pA = nullptr;
	ListNode *pB = nullptr;
	StringIntToIntersectionNode(&pA, &pB, l1, l2, k1, k2);
	ListNode *pNode = getIntersectionNode(pA, pB);
	if (pNode == nullptr) return "null";
	return to_string(pNode->val);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

