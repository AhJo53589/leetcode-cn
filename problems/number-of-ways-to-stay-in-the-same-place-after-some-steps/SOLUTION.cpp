


//////////////////////////////////////////////////////////////////////////
long long ans[510][510];
int numWays(int steps, int arrLen)
{
	long long mod = 1000000007;
	memset(ans, 0, sizeof(ans));
	arrLen = min(arrLen, steps + 1);
	ans[0][0] = 1;
	for (int i = 1; i <= steps + 1; i++)
	{
		for (int j = 0; j < arrLen; j++)
		{
			ans[i][j] = ans[i - 1][j];
			if (j != 0)
			{
				ans[i][j] += ans[i - 1][j - 1];
			}
			if (j != arrLen - 1)
			{
				ans[i][j] += ans[i - 1][j + 1];
			}
			ans[i][j] %= mod;
		}
	}
	return ans[steps][0] % mod;
}

//////////////////////////////////////////////////////////////////////////
//long long dp[510][510];
//int numWays(int steps, int arrLen)
//{
//	const int mod = 1e9 + 7;
//	memset(dp, 0, sizeof(dp));
//	dp[0][0] = 1;
//	for (int i = 1; i <= steps; ++i) 
//	{
//		for (int j = 0; j < min(505, arrLen); ++j) 
//		{
//			dp[i][j] = j > 0 ? ((dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod) : (dp[i - 1][j + 1]);
//			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
//		}
//	}
//}

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

