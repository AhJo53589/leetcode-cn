


//////////////////////////////////////////////////////////////////////////
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
	vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));

	for (size_t i = 0; i < obstacleGrid.size(); i++)
	{
		for (size_t j = 0; j < obstacleGrid[0].size(); j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 1;
				dp[i][j] = (i != 0 && dp[i - 1][j] == 0) ? 0 : 1;
				dp[i][j] = (j != 0 && dp[i][j - 1] == 0) ? 0 : 1;
			}
			else
			{
				if (obstacleGrid[i][j] == 1)
				{
					dp[i][j] = 0;
					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& obstacleGrid)
{
	return uniquePathsWithObstacles(obstacleGrid);
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
	return "../../problems/_test_0/tests.txt";
}

