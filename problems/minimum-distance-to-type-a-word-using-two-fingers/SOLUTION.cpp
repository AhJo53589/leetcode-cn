


//////////////////////////////////////////////////////////////////////////
int M[26][2] = 
{
	{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5},
	{1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5},
	{2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5},
	{3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5},
	{4, 0}, {4, 1}
};

int dist(int i, int j)
{
	return abs(M[i][0] - M[j][0]) + abs(M[i][1] - M[j][1]);
}

int minimumDistance(string word) 
{
	int N = word.size();
	if (N < 2) return 0;

	vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(26, vector<int>(26, INT_MAX - 10)));
	int step = 0;
	for (int i = 0; i < 26; ++i) 
	{
		for (int j = 0; j < 26; ++j) 
		{
			dp[0][i][j] = 0;
		}
	}

	for (int i = 1; i <= N; ++i) 
	{
		int curr = word[i - 1] - 'A';
		for (int j = 0; j < 26; ++j) 
		{
			for (int k = 0; k < 26; ++k) 
			{
				dp[i][curr][j] = min(dp[i][curr][j], dp[i - 1][k][j] + dist(curr, k));
				dp[i][curr][j] = min(dp[i][curr][j], dp[i - 1][curr][k] + dist(k, j));

				dp[i][j][curr] = min(dp[i][j][curr], dp[i - 1][j][k] + dist(curr, k));
				dp[i][j][curr] = min(dp[i][j][curr], dp[i - 1][k][curr] + dist(k, j));
			}
		}
	}

	int ans = INT_MAX;
	int ind = word[N - 1] - 'A';
	for (int i = 0; i < 26; ++i) 
	{
		ans = min(ans, dp[N][ind][i]);
		ans = min(ans, dp[N][i][ind]);
	}
	return ans;
}

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

