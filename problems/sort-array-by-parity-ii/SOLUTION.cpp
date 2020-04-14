
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) 
    {
        for (int i = 0, j = 1; i < A.size(); i += 2) 
        {
            if (A[i] % 2 == 1) 
            {
                while (A[j] % 2 == 1)
                {
                    j += 2;
                }
                swap(A[i], A[j]);
            }
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
    return sln.sortArrayByParityII(A);
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
