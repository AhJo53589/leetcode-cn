


//////////////////////////////////////////////////////////////////////////
int minCostClimbingStairs(vector<int>& cost)
{
	int dp[1001];
	memset(&dp, 0, sizeof(dp));
	for (size_t i = 0; i < cost.size() + 1; i++)
	{
		if (i == 0 || i == 1)
		{
			dp[i] = cost[i];
		}
		else if (i == cost.size())
		{
			dp[i] = min(dp[i - 2], dp[i - 1]);
		}
		else
		{
			dp[i] = min(dp[i - 2] + cost[i], dp[i - 1] + cost[i]);
		}
	}
	return dp[cost.size()];
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& cost)
{
	return minCostClimbingStairs(cost);
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

