
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int calculate(string s) {
        int x = 1;
        int y = 0;
        for (auto c : s) {
            if (c == 'A') {
                x = 2 * x + y;
            }
            else if (c == 'B') {
                y = 2 * y + x;
            }
        }
        return x + y;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.calculate(s);
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
