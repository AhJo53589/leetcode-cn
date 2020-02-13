


//////////////////////////////////////////////////////////////////////////
int minDifficulty(vector<int>& jobDifficulty, int d)
{
	int n = jobDifficulty.size();
	vector<vector<int>> dp(d + 1, vector<int>(n + 1, INT_MAX));
	dp[0][0] = 0;

	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int mx = 0;
			for (int k = j - 1; k >= 0; k--)
			{
				mx = max(mx, jobDifficulty[k]);
				if (dp[i - 1][k] == INT_MAX) continue;
				dp[i][j] = min(dp[i][j], mx + dp[i - 1][k]);
			}
		}
	}

	return (dp[d][n] == INT_MAX) ? -1 : dp[d][n];
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& jobDifficulty, int d)
{
	return minDifficulty(jobDifficulty,d);
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

