


//////////////////////////////////////////////////////////////////////////
int minimumTotal(vector<vector<int>>& triangle)
{
	if (triangle.empty()) return 0;
	vector<int> dp(triangle.back().begin(), triangle.back().end());

	for (int i = triangle.size() - 2; i >= 0; i--)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
		}
	}
	return dp[0];
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& triangle)
{
	return minimumTotal(triangle);
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

