
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2)
	{
		int ans = 0;
		vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
		for (int i = 1; i <= text1.size(); i++)
		{
			for (int j = 1; j <= text2.size(); j++)
			{
				if (text1[i - 1] == text2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
				ans = max(ans, dp[i][j]);
			}
		}
		return ans;
	}
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string text1, string text2)
{
	//int caseNo = 2;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.longestCommonSubsequence(text1,text2);
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
