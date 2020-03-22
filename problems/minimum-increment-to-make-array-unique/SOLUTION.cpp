
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minIncrementForUnique(vector<int>& A)
    {
        if (A.empty()) return 0;
        sort(A.begin(), A.end());
        int ans = 0;
        int st = A[0];
        for (int i = 0; i < A.size(); i++)
        {
            st = max(st, A[i]);
            ans += (A[i] < st) ? st - A[i] : 0;
            st++;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& A)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minIncrementForUnique(A);
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
