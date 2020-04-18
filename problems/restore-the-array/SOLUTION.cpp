
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numberOfArrays(string s, int k)
    {
        const int mod = 1e9 + 7;
        if (s.size() <= 1) return 1;

        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= max(1, i - 9) - 1; j--)
            {
                string t = s.substr(j, i - j);
                if (t[0] == '0') continue;

                long n = stol(t);
                if (n > k) break;

                dp[i] = ((dp[i] % mod) + (dp[j] % mod)) % mod;
            }
        }
        return dp.back();
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.numberOfArrays(s, k);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
