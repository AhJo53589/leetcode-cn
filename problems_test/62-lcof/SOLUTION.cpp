
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int lastRemaining(int n, int m)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = (ans + m) % i;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int lastRemaining(int n, int m)
    {
        return (n == 1) ? 0 : (lastRemaining(n - 1, m) + m) % n;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, int m)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.lastRemaining(n, m);
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
