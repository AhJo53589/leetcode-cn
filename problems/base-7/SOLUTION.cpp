
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string convertToBase7(int num) 
    {
        if (num < 0) return "-" + convertToBase7(-1 * num);
        if (num < 7) return to_string(num);
        return convertToBase7(num / 7) + to_string(num % 7);
    }
};


//////////////////////////////////////////////////////////////////////////
string _solution_run(int num)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.convertToBase7(num);
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
