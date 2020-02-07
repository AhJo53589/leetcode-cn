
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxProfit(vector<int>& prices) 
	{
		if (prices.empty()) return 0;
		int max_k = 2;
		vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(max_k + 1, vector<int>(2, 0)));
		for (size_t i = 0; i < prices.size(); i++)
		{
			for (size_t k = max_k; k >= 1; k--)
			{
				if (i == 0)
				{
					dp[i][k][0] = 0;
					dp[i][k][1] = -prices[i];
					continue;
				}
				dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
				dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
			}
		}
		return dp[prices.size() - 1][max_k][0];
    }
};

//////////////////////////////////////////////////////////////////////////

int _solution_run(vector<int>& prices)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maxProfit(prices);
}

//#define USE_SOLUTION_CUSTOM
//
//int _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
