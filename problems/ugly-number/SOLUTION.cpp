
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isUgly(int num)
    {
        if (num == 0) return false;
        while (num % 2 == 0)
        {
            num /= 2;
        }
        while (num % 3 == 0)
        {
            num /= 3;
        }
        while (num % 5 == 0)
        {
            num /= 5;
        }
        return num == 1;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(int num)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.isUgly(num);
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
