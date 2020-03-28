
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool checkRecord(string s) 
    {
        int cnt_A = 0;
        int cnt_L = 0;
        for (auto c : s)
        {
            cnt_A += (c == 'A');
            cnt_L = (c != 'L') ? 0 : cnt_L;
            cnt_L += (c == 'L');
            if (cnt_A > 1 || cnt_L > 2) return false;
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.checkRecord(s);
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
