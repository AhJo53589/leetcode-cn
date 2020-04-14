
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int binaryGap(int N)
    {
        int ans = 0;
        int pos = -1;
        int onePos = -1;
        while (N > 0)
        {
            pos++;
            if (N % 2 == 1)
            {
                ans = (onePos != -1) ? max(ans, pos - onePos) : ans;
                onePos = pos;
            }
            N = N / 2;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int N)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.binaryGap(N);
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
