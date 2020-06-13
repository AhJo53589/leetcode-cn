
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(2, 0);
        dp[1] = 1;
        dp[2 % 2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i % 2] = dp[(i + 1) % 2] + dp[i % 2];
        }
        return dp[n % 2];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.climbStairs(n);
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
