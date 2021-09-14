
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxProduct(string s) {
        int ans = 0;
        for (int i = 0; i < (1 << s.size()); i++) {
            string a, b;
            for (int j = 0; j < s.size(); j++) {
                if (i & (1 << j)) {
                    a += s[j];
                }
                else {
                    b += s[j];
                }
            }
            
            if (a.empty() || b.empty()) continue;
            int x = longestPalindromeSubseq(a);
            int y = longestPalindromeSubseq(b);
            ans = max(ans, x * y);
        }
        return ans;
    }

    int longestPalindromeSubseq(string& s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = (int)s.size() - 1; ~i; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp.front().back();
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxProduct(s);
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
