
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
	int maxProfit(vector<int>& prices)	// 4ms
	{
		if (prices.size() < 2)return 0;
		int hold = -prices[0], unhold = 0;
		for (int i = 1; i < prices.size(); ++i) {
			int tmp = hold;
			hold = max(hold, unhold - prices[i]);
			unhold = max(unhold, tmp + prices[i]);
		}
		return unhold;
	}

	int maxProfit_dp(vector<int>& prices)
	{
		int dp_i_0 = 0;
		int dp_i_1 = INT_MIN;
		for (int i = 0; i < prices.size(); i++) {
			int temp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, temp - prices[i]);
		}
		return dp_i_0;
	}
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.size() < 2) return 0;
		int ans = 0;
		for (size_t i = 1; i < prices.size(); i++)
		{
			if (prices[i - 1] >= prices[i]) continue;
			ans += prices[i] - prices[i - 1];
		}
		return ans;
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
