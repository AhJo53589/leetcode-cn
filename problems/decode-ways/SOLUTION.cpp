
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        s += '0';

        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < s.size(); i++) {
            int a = s[i - 1] - '0';
            int b = s[i] - '0';
            if (a == 0) continue;

            int ii = i + 1;
            dp[ii - 1] += dp[ii - 2];

            if (a * 10 + b <= 26) {
                dp[ii] = dp[ii - 2];
            }
        }
        dp.pop_back();
        return dp.back();
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
    return sln.numDecodings(s);
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
