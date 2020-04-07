
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) 
    {
        int l = 0;
        for (int r = 0; r < A.size(); r++)
        {
            if ((A[r] & 1) != 0) continue;
            swap(A[l++], A[r]);
        }
        return A;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& A)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(A);
    Solution sln;
    return sln.sortArrayByParity(A);
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
