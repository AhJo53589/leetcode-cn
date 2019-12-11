

//////////////////////////////////////////////////////////////////////////
//int getMoneyAmount(int n) {
//	vector<vector<int> > dp(n + 1, vector<int>(n + 1, INT_MAX));
//	for (int i = 0; i <= n; ++i) {
//		dp[i][i] = 0;
//	}
//	for (int len = 2; len <= n; ++len) {
//		for (int i = 1; i <= n && i + len - 1 <= n; ++i) {
//			int j = i + len - 1;
//			dp[i][j] = min(i + dp[i + 1][j], j + dp[i][j - 1]);
//			for (int k = i + 1; k < j; ++k) {
//				dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
//			}
//		}
//	}
//	return dp[1][n];
//}

//////////////////////////////////////////////////////////////////////////
int calc(map<vector<int>, int>& cache, int low, int high)
{
	if (low >= high) return 0;
	if (low + 1 == high) return low;

	if (cache.count({ low, high }) != 0)
	{
		return cache[{low, high}];
	}

	int ans = INT_MAX;
	for (int i = (low + high) / 2; i <= high; i++)
	{
		int r = i + max(calc(cache, low, i - 1), calc(cache, i + 1, high));
		ans = min(ans, r);
	}
	cache[{low, high}] = ans;
	return ans;
}

int getMoneyAmount(int n) 
{
	map<vector<int>, int> cache;
	return calc(cache, 1, n);
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	return getMoneyAmount(n);
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
	return "../../problems/guess-number-higher-or-lower-ii/tests.txt";
}

