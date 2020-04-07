
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        n = (n ^ (n >> 1));
        return (n & ((long)n + 1)) == 0;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.hasAlternatingBits(n);
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
