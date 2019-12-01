


//////////////////////////////////////////////////////////////////////////
int change(string &s, int left, int right)
{
	int ret = 0;
	while (left < right) 
	{
		if (s[left++] != s[right--]) 
		{
			ret++;
		}
	}
	return ret;
}

int palindromePartition(string s, int k) 
{
	vector<vector<int>> dp = vector<vector<int>>(k + 1, vector<int>(s.size() + 1, -1));
	dp[0][0] = 0;
	for (int j = 1; j <= s.size(); j++) 
	{
		for (int p = 0; p < j; p++)
		{
			int cache = change(s, p, j - 1);
			for (int i = 1; i <= k; i++) 
			{
				if (dp[i - 1][p] == -1) 
				{
					continue;
				}
				int sub = dp[i - 1][p] + cache;
				if (dp[i][j] == -1) 
				{
					dp[i][j] = sub;
				}
				else
				{
					dp[i][j] = min(dp[i][j], sub);
				}
			}
		}
	}
	return dp[k][s.size()];
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s, int k)
{
	return palindromePartition(s,k);
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
	return "../../problems/_test_0/tests.txt";
}

