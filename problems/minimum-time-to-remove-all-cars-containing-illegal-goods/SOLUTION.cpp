
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimumTime(string s) {
        vector<vector<int>> dp(2, vector<int>(1, 0));
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == '0') continue;
                dp[i].push_back(min(j + 1, dp[i].back() + 2));
            }
            dp[i].push_back(0);
            reverse(s.begin(), s.end());
        }
        reverse(dp[1].begin(), dp[1].end());

        int ans = INT_MAX;
        for (int i = 0; i < dp[0].size() - 1; i++) {
            ans = min(dp[0][i] + dp[1][i + 1], ans);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minimumTime(s);
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
