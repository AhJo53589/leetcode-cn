//////////////////////////////////////////////////////////////////////////////
//int minimumDistance(string word)
//{
//	auto dist = [](int a, int b)
//	{
//		return abs((a / 6) - (b / 6)) + abs((a % 6) - (b % 6));
//	};
//
//	vector<vector<int>> dp(word.size(), vector<int>(26, INT_MAX));
//	for (size_t i = 0; i < 26; i++)
//	{
//		dp[0][i] = 0;
//	}
//
//	for (size_t i = 1; i < word.size(); i++)
//	{
//		int prev = word[i - 1] - 'A';
//		int cur = word[i] - 'A';
//
//		vector<int>& prev_dp = dp[i - 1];
//		vector<int>& cur_dp = dp[i];
//
//		for (int j = 0; j < 26; j++)
//		{
//			int distance = dist(j, cur) + prev_dp[j];
//			cur_dp[prev] = min(cur_dp[prev], distance);
//
//			distance = dist(prev, cur) + prev_dp[j];
//			cur_dp[j] = min(cur_dp[j], distance);
//		}
//	}
//
//	int ans = INT_MAX;
//	for (auto n : dp.back())
//	{
//		ans = min(ans, n);
//	}
//	return ans;
//}


////////////////////////////////////////////////////////////////////////////////
int minimumDistance(string word)
{
	auto dist = [](int a, int b)
	{
		return abs((a / 6) - (b / 6)) + abs((a % 6) - (b % 6));
	};

	vector<int> dp(26, 0);
	for (size_t i = 1; i < word.size(); i++)
	{
		int prev = word[i - 1] - 'A';
		int cur = word[i] - 'A';
		if (cur == prev) continue;

		vector<int> prev_dp = dp;
		dp = vector<int>(26, INT_MAX);

		for (int j = 0; j < 26; j++)
		{
			int distance = dist(j, cur) + prev_dp[j];
			dp[prev] = min(dp[prev], distance);

			distance = dist(prev, cur) + prev_dp[j];
			dp[j] = min(dp[j], distance);
		}
	}

	int ans = INT_MAX;
	for (auto n : dp)
	{
		ans = min(ans, n);
	}
	return ans;
}


//////////////////////////////////////////////////////////////////////////
//int M[26][2] = 
//{
//	{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5},
//	{1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5},
//	{2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5},
//	{3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5},
//	{4, 0}, {4, 1}
//};
//
//int dist(int i, int j)
//{
//	return abs(M[i][0] - M[j][0]) + abs(M[i][1] - M[j][1]);
//}
//
//int minimumDistance(string word) 
//{
//	int N = word.size();
//	if (N < 2) return 0;
//
//	vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(26, vector<int>(26, INT_MAX - 10)));
//	int step = 0;
//	for (int i = 0; i < 26; ++i) 
//	{
//		for (int j = 0; j < 26; ++j) 
//		{
//			dp[0][i][j] = 0;
//		}
//	}
//
//	for (int i = 1; i <= N; ++i) 
//	{
//		int curr = word[i - 1] - 'A';
//		for (int j = 0; j < 26; ++j) 
//		{
//			for (int k = 0; k < 26; ++k) 
//			{
//				dp[i][curr][j] = min(dp[i][curr][j], dp[i - 1][k][j] + dist(curr, k));
//				dp[i][curr][j] = min(dp[i][curr][j], dp[i - 1][curr][k] + dist(k, j));
//
//				dp[i][j][curr] = min(dp[i][j][curr], dp[i - 1][j][k] + dist(curr, k));
//				dp[i][j][curr] = min(dp[i][j][curr], dp[i - 1][k][curr] + dist(k, j));
//			}
//		}
//	}
//
//	int ans = INT_MAX;
//	int ind = word[N - 1] - 'A';
//	for (int i = 0; i < 26; ++i) 
//	{
//		ans = min(ans, dp[N][ind][i]);
//		ans = min(ans, dp[N][i][ind]);
//	}
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string word)
{
	return minimumDistance(word);
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
	return "../../problems/minimum-distance-to-type-a-word-using-two-fingers/tests.txt";
}

