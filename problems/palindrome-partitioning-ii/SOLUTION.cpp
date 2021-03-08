
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minCut(string s) {
        vector<int> v(s.size(), 0);
        for (int i = 1; i < s.size(); i++) {
            calc(s, i, i, v);
            calc(s, i, i - 1, v);
        }

        vector<int> dp(s.size() + 1, INT_MAX);
        dp[0] = -1;
        for (int i = 0; i < dp.size(); i++) {
            if (i != 0) {
                dp[i] = min(dp[i - 1] + 1, dp[i]);
            }
            if (i != s.size()) {
                dp[v[i] + 1] = min(dp[v[i] + 1], dp[i] + 1);
            }
        }
        return dp.back();
    }

    void calc(string& s, int l, int r, vector<int>& v) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            v[l] = max(v[l], r);
            l--;
            r++;
        }
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    cout << s << endl;

    Solution sln;
    return sln.minCut(s);
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
