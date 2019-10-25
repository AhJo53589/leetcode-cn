
//////////////////////////////////////////////////////////////////////////
//int maxProfit(vector<int>& prices) // 8ms
//{
//	int len = prices.size();
//	if (len <= 1)
//		return 0;
//	int res = 0;
//	for (int i = 0; i < len - 1; i++)
//		if (prices[i + 1] - prices[i] > 0)
//			res += prices[i + 1] - prices[i];
//	return res;
//}

//////////////////////////////////////////////////////////////////////////
//int maxProfit(vector<int>& prices)	// 12ms
//{
//	if (prices.size() < 2) return 0;
//
//	int iLen = prices.size();
//	int iMaxValue = 0;
//	int high = prices[iLen - 1];
//	int low = high;
//	int j = iLen - 2;
//	while (j >= 0)
//	{
//		if (high < prices[j])
//		{
//			if (low < high)
//			{
//				iMaxValue += high - low;
//			}
//			high = prices[j];
//			low = high;
//		}
//		else
//		{
//			if (prices[j] < low)
//			{
//				low = prices[j];
//			}
//			else
//			{
//				iMaxValue += high - low;
//				high = prices[j];
//				low = high;
//			}
//		}
//		j--;
//	}
//	if (low < high)
//	{
//		iMaxValue += high - low;
//	}
//	return iMaxValue;
//}


//////////////////////////////////////////////////////////////////////////
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
	return "../../problems/best-time-to-buy-and-sell-stock-ii/tests.txt";
}

