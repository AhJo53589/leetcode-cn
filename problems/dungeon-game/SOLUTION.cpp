
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size() + 1, vector<int>(dungeon[0].size() + 1, INT_MAX));
        dp[dungeon.size()][dungeon[0].size() - 1] = 1;
        dp[dungeon.size() - 1][dungeon[0].size()] = 1;

        for (int i = dungeon.size() - 1; i >= 0; i--) {
            for (int j = dungeon[i].size() - 1; j >= 0; j--) {
                int m = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(m - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& dungeon)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.calculateMinimumHP(dungeon);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
