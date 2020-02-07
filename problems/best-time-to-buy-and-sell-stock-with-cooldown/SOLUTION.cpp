
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		int dp_i_0 = 0;
		int dp_i_1 = INT_MIN;
		int dp_pre_0 = 0;	// ´ú±í dp[i-2][0]
		for (size_t i = 0; i < prices.size(); i++)
		{
			int temp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
			dp_pre_0 = temp;
		}
		return dp_i_0;
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
