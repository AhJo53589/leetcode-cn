


//////////////////////////////////////////////////////////////////////////
int helper(string& text1, string& text2, int i, int j, vector<vector<int>>& dp)
{
	if (i == text1.size() || j == text2.size()) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	if (text1[i] == text2[j])
	{
		dp[i][j] = max(dp[i][j], helper(text1, text2, i + 1, j + 1, dp) + 1);
	}
	else
	{
		dp[i][j] = max(dp[i][j], helper(text1, text2, i + 1, j, dp));
		dp[i][j] = max(dp[i][j], helper(text1, text2, i, j + 1, dp));
	}
	return dp[i][j];
}

int longestCommonSubsequence(string text1, string text2)
{
	vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
	return helper(text1, text2, 0, 0, dp);
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string text1, string text2)
{
	int caseNo = -1;
	static int caseCnt = 0;
	if (caseNo != -1 && caseCnt++ != caseNo) return {};

	return longestCommonSubsequence(text1,text2);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
