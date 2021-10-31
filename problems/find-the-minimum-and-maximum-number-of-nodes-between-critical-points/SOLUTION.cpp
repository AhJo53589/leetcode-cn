
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> idx;
        ListNode* p = head;
        head = head->next;
        int i = 1;
        while (head != nullptr && head->next != nullptr) {
            if ((head->val > head->next->val&& head->val > p->val)
                || (head->val < head->next->val && head->val < p->val)) {
                idx.push_back(i);
            }
            p = head;
            head = head->next;
            i++;
        }

        int _min = (idx.size() > 1) ? INT_MAX : -1;
        int _max = (idx.size() > 1) ? idx.back() - idx.front() : -1;
        for (int i = 1; i < idx.size(); i++) {
            _min = min(idx[i] - idx[i - 1], _min);
        }
        return vector<int>{_min, _max};
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(ListNode* head)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << head << endl;
    Solution sln;
    return sln.nodesBetweenCriticalPoints(head);
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
