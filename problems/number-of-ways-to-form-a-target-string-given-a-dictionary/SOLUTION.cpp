
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const long long mod = 1e9 + 7;
        vector<vector<int>> cnt(words[0].size(), vector<int>(26, 0));
        for (auto w : words) {
            for (int i = 0; i < w.size(); i++) {
                cnt[i][w[i] - 'a']++;
            }
        }

        int df = cnt.size() - target.size();

        vector<vector<long long>> dp(target.size(), vector<long long>(cnt.size(), 0));
        for (int i = 0; i < target.size(); i++) {
            for (int j = 0; j < cnt.size(); j++) {
                if (abs(i - j) > df) continue;
                int t = target[i] - 'a';
                if (cnt[j][t] == 0) continue;
                if (i == 0) {
                    dp[i][j] = cnt[j][t];
                }
                else {
                    int temp = 0;
                    for (int k = 0; k < j; k++) {
                        temp += dp[i - 1][k];
                    }
                    dp[i][j] = ksc(cnt[j][t], temp, mod);
                }
            }
        }

        long long ans = 0;
        for (int j = 0; j < cnt.size(); j++) {
            ans += dp[target.size() - 1][j];
            ans %= mod;
        }
        return (int)ans;
    }

    long long ksc(long long a, long long b, long long mod) {
        long long res = 0;
        while (b) {
            if (b & 1) res = (res + a) % mod;
            (a <<= 1) %= mod;
            b >>= 1;
        }
        return res;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& words, string target)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(words);
    cout << target << endl;
    Solution sln;
    return sln.numWays(words, target);
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
