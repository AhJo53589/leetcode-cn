


//////////////////////////////////////////////////////////////////////////
int minPathSum(vector<vector<int>>& grid) 
{
	vector<vector<int>> dp(grid.size(), vector<int>());
	for (auto &p : dp)
	{
		p.resize(grid[0].size());
	}

	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t j = 0; j < grid[i].size(); j++)
		{
			if (i == 0 && j == 0)
			{
				dp[i][j] = grid[i][j];
			}
			else if (i == 0)
			{
				dp[i][j] = dp[i][j - 1] + grid[i][j];
			}
			else if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + grid[i][j];
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}
	}
	return dp.back().back();
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
	return minPathSum(grid);
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

