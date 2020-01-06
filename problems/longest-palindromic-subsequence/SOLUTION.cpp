


//////////////////////////////////////////////////////////////////////////
int longestPalindromeSubseq(string s) 
{
	vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
	for (size_t i = s.size() - 1; i < s.size(); i--)
	{
		dp[i][i] = 1;
		for (size_t j = i + 1; j < s.size(); j++)
		{
			if (s[i] == s[j])
			{
				dp[i][j] = dp[i + 1][j - 1] + 2;
			}
			else
			{
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[0].back();
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	return longestPalindromeSubseq(s);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/longest-palindromic-subsequence/tests.txt";
}

