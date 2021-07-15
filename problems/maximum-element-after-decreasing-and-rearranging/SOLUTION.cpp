
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        auto pq = priority_queue {greater<int>{}, arr};
        int ans = 0;
        while (!pq.empty()) {
            ans = min(ans + 1, pq.top());
            pq.pop();
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maximumElementAfterDecrementingAndRearranging(arr);
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
