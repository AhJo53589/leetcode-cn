
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numSubmat(vector<vector<int>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (!matrix[i][j]) continue;
                dp[i][j] = (j == 0) ? 1 : dp[i][j - 1] + 1;

                int width = dp[i][j];
                for (int k = i; k >= 0; k--) {
                    width = min(width, dp[k][j]);
                    ans += width;
                    if (width == 0) break;
                }
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& mat)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.numSubmat(mat);
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
