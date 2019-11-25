
//////////////////////////////////////////////////////////////////////////
int numWays(int steps, int arrLen)
{
	const int mod = 1e9 + 7;
	int dp[502][502];
	memset(dp, 0, sizeof(dp));
	arrLen = min(steps, arrLen);
	dp[0][0] = 1;
	for (size_t i = 1; i <= steps; i++)
	{
		for (size_t j = 0; j < arrLen; j++)
		{
			if (j != 0)
			{
				dp[i][j] += dp[i - 1][j - 1];
			}
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= mod;
			dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= mod;
		}
	}
	return dp[steps][0];
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(int steps, int arrLen)
{
	return numWays(steps,arrLen);
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
	return "../../problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/tests.txt";
}

