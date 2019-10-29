
//////////////////////////////////////////////////////////////////////////
//int coinChange(vector<int>& coins, int amount)
//{
//	if (amount == 0) return 0;
//	sort(coins.begin(), coins.end());
//	vector<int> _in;
//	vector<int> _out;
//	unordered_set<int> _set;
//
//	for (int i = 0; i < coins.size(); i++)
//	{
//		if (coins[i] == amount) return 1;
//		if (coins[i] > amount) continue;
//		_in.push_back(coins[i]);
//		_set.insert(coins[i]);
//	}
//	int k = 2;
//	while (!_in.empty())
//	{
//		bool bOverFlag = true;
//		for (auto &a : _in)
//		{
//			for (auto &c : coins)
//			{
//				if (a + c == amount) return k;
//				if (a + c > amount)
//				{
//					if (bOverFlag) return -1;
//					continue;
//				}
//				bOverFlag = false;
//				if (_set.count(a + c)) continue;
//				_out.push_back(a + c);
//				_set.insert(a + c);
//			}
//		}
//		k++;
//		_in.swap(_out);
//		_out.clear();
//	}
//	return -1;
//}

//////////////////////////////////////////////////////////////////////////
void coinChange(vector<int>& coins, int amount, int c_index, int count, int &ans)
{
	if (amount == 0)
	{
		ans = min(ans, count);
		return;
	}
	if (c_index == coins.size()) return;

	for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)
	{
		coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
	}
}

//////////////////////////////////////////////////////////////////////////
int coinChange(vector<int>& coins, int amount)
{
	if (amount == 0) return 0;
	sort(coins.rbegin(), coins.rend());
	int ans = INT_MAX;
	coinChange(coins, amount, 0, 0, ans);
	return ans == INT_MAX ? -1 : ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& coins, int amount)
{
	return coinChange(coins,amount);
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
	return "../../problems/coin-change/tests.txt";
}

