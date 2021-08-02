
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        priority_queue<int> pq(milestones.begin(), milestones.end());
        long long ans = 0;
        long long remain = pq.top();
        pq.pop();
        long long success = 0;
        while (!pq.empty()) {
            long long next = pq.top();
            pq.pop();

            ans += 2LL * min(remain, next);

            if (remain < next) {
                success = ans;
            }
            remain = abs(remain - next);
        }

        ans += min(success, remain);
        ans += (remain > success);

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
long _solution_run(vector<int>& milestones)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(milestones);
    Solution sln;
    return sln.numberOfWeeks(milestones);
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
