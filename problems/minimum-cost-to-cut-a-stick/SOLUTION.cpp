
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector<int> sticks;
        sticks.reserve(cuts.size() + 1);
        int prevCut = 0;
        for (auto cut : cuts) {
            sticks.push_back(cut - prevCut);
            prevCut = cut;
        }
        sticks.push_back(n - prevCut);
        int m = sticks.size();
        // dp[i][j]表示sticks[i..j]合并需要的最小代价
        vector<vector<int>> dp(m, vector<int>(m, numeric_limits<int>::max()));
        vector<int> prefixSum(m + 1, 0);
        for (int i = 0; i < m; ++i) {
            dp[i][i] = 0;
            prefixSum[i + 1] = prefixSum[i] + sticks[i];
        }
        for (int count = 1; count <= m; ++count) {
            for (int i = 0; i + count < m; ++i) {
                int j = i + count;
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] += prefixSum[j + 1] - prefixSum[i];
            }
        }
        return dp[0][m - 1];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<int>& cuts)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minCost(n, cuts);
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
