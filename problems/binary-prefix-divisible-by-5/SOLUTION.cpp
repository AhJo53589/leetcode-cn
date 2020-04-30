
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int sum = 0;
        vector<bool> ans(A.size(), false);
        for (int i = 0; i < A.size(); i++) {
            sum = 2 * sum + A[i];
            sum = sum % 5;
            ans[i] = (sum % 5 == 0);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<bool> _solution_run(vector<int>& A)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.prefixesDivBy5(A);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
