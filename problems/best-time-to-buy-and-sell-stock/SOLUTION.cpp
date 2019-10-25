


//////////////////////////////////////////////////////////////////////////
int maxProfit(vector<int>& prices)
{
	int minPrice = INT_MAX;
	int maxProfit = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		minPrice = min(minPrice, prices[i]);
		maxProfit = max(maxProfit, prices[i] - minPrice);
	}
	return maxProfit;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& prices)
{
	return maxProfit(prices);
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
	return "../../problems/best-time-to-buy-and-sell-stock/tests.txt";
}

