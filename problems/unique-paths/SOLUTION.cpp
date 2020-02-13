
//////////////////////////////////////////////////////////////////////////
//int uniquePaths(int m, int n)
//{
//	if (m == 1 || n == 1) return 1;
//	return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
//}


//////////////////////////////////////////////////////////////////////////
int uniquePaths(int m, int n)
{
	int dp[101][101] = { 0 };
	for (int i = 0; i < m; i++)
	{
		dp[i][0] = 1;
	}
	for (int j = 0; j < n; j++)
	{
		dp[0][j] = 1;
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(int m, int n)
{
	return uniquePaths(m,n);
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

