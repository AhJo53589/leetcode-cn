


//////////////////////////////////////////////////////////////////////////
int maxSideLength(vector<vector<int>>& mat, int threshold)
{
	vector<vector<int>> dp(mat.size() + 1, vector<int>());
	for (auto &d : dp) d.resize(mat[0].size() + 1);

	int ans = 0;
	dp[0][0] = mat[0][0];
	for (size_t i = 1; i < mat.size(); i++)
	{
		dp[i][0] = mat[i][0] + dp[i - 1][0];
	}
	for (size_t j = 1; j < mat[0].size(); j++)
	{
		dp[0][j] = mat[0][j] + dp[0][j - 1];
	}
	for (size_t i = 1; i <= mat.size(); i++)
	{
		for (size_t j = 1; j <= mat[0].size(); j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			if (i != mat.size() && j != mat[0].size())
			{
				dp[i][j] += mat[i][j];
			}
		}
	}

	for (int len = 1; len <= min(mat.size(), mat[0].size()); len++)
	{
		for (size_t i = len - 1; i < mat.size(); i++)
		{
			if (ans == len) break;
			for (size_t j = len - 1; j < mat[0].size(); j++)
			{
				int ts = dp[i][j];
				if (i - len < dp.size())
				{
					ts -= dp[i - len][j];
				}
				if (j - len < dp[0].size())
				{
					ts -= dp[i][j - len];
				}
				if (i - len < dp.size() && j - len < dp[0].size())
				{
					ts += dp[i - len][j - len];
				}
				if (ts > threshold) continue;
				ans = max(ans, len);
				break;
			}
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& mat, int threshold)
{
	return maxSideLength(mat,threshold);
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
	return "../../problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/tests.txt";
}

