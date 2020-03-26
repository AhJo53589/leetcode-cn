
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int arrangeCoins(int n) {
        return int(sqrt(double(2 * (double)n + 0.25)) - 0.5);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.arrangeCoins(n);
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
