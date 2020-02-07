
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	int maxProfit_k_any(int max_k, vector<int>& prices)
	{
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
	
	int maxProfit_k_inf(vector<int>& prices)
	{
		int dp_i_0 = 0;
		int dp_i_1 = INT_MIN;
		for (size_t i = 0; i < prices.size(); i++)
		{
			int temp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, temp - prices[i]);
		}
		return dp_i_0;
	}

    int maxProfit(int k, vector<int>& prices) 
	{
		return (k > prices.size() / 2) ? maxProfit_k_inf(prices) : maxProfit_k_any(k, prices);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int k, vector<int>& prices)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maxProfit(k,prices);
}

//#define USE_SOLUTION_CUSTOM
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
