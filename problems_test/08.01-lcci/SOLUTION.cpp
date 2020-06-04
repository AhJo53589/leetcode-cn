
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    const int mod = 1e9 + 7;

    int waysToStep(int n) {
        if (n == 0) return 0;

        vector<int> dp(3, 0);
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 4;

        for (int i = 3; i < n; i++) {
            int idx = i % 3;
            dp[idx] = ((dp[0] + dp[1]) % mod + dp[2]) % mod;
        }

        return dp[(n - 1) % 3];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.waysToStep(n);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
