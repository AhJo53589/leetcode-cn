
//////////////////////////////////////////////////////////////////////////
//double probabilityOfHeads(vector<double>& prob, int target)
//{
//	int len = prob.size();
//	vector<double> res(target + 1, 0);
//	// 初试，掷出 0 的概率为 1
//	res[0] = 1.0;
//	for (int i = 1; i <= len; i++)
//		// 倒着更新，省一维空间
//		for (int j = min(i, target); j >= 0; j--)
//			// 当前掷出 j 个    当前掷出的为反面 * 上次掷出了 j 个    当前掷出的为正面 * 上次掷出了 j - 1 个
//			res[j] = res[j] * (1 - prob[i - 1]) + (j > 0 ? res[j - 1] * prob[i - 1] : 0);
//
//	return res[target];
//}

//////////////////////////////////////////////////////////////////////////
double probabilityOfHeads(vector<double>& prob, int target)
{
	int N = prob.size();
	vector<vector<double>> dp(N, vector<double>(target + 2));
	dp[0][0] = 1 - prob[0];
	dp[0][1] = prob[0];
	for (int i = 1; i < N; i++) 
	{
		dp[i][0] = dp[i - 1][0] * (1 - prob[i]);
		for (int j = 1; j <= target; j++) 
		{
			dp[i][j] = dp[i - 1][j] * (1 - prob[i]) + dp[i - 1][j - 1] * prob[i];
		}
	}

	return dp[N - 1][target];
}

//////////////////////////////////////////////////////////////////////////
double _solution_run(vector<double>& prob, int target)
{
	return probabilityOfHeads(prob,target);
}

//#define USE_SOLUTION_CUSTOM
//double _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

//#define USE_GET_TEST_CASES_FILESTREAM
//string _get_test_cases_filestream()
//{
//	return "../../problems/toss-strange-coins/tests.txt";
//}

