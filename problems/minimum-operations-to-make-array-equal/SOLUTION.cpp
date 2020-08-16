
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minOperations(int n) {
        if (n % 2 == 0) {
            return n * n / 4;
        }
        else {
            return (2 + 2 * (n / 2)) * (n / 2) / 2;
        }
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minOperations(n);
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
