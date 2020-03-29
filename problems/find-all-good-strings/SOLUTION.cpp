
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    const int MOD = 1000000007;
    int findGoodStrings(int n, string a, string b, string s) {
        if (a > b) return 0;

        int m = s.size();
        vector<int> fail(m + 1);
        for (int i = 2; i <= m; ++i)
        {
            int j = fail[i - 1];
            while (j && s[j + 1 - 1] != s[i - 1]) j = fail[j];
            fail[i] = s[j + 1 - 1] == s[i - 1] ? j + 1 : 0;
        }
        vector<vector<int>> next(m + 1, vector<int>(26));
        for (int i = 0; i < m; ++i)
            for (int c = 0; c < 26; ++c)
            {
                int j = i;
                while (j && s[j + 1 - 1] != c + 'a') j = fail[j];
                next[i][c] = s[j + 1 - 1] == c + 'a' ? j + 1 : 0;
            }

        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for (int j = 0; j < m; ++j)
            f[0][j] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                f[i][j] = 0;
                for (int c = 0; c < 26; ++c)
                {
                    (f[i][j] += f[i - 1][next[j][c]]) %= MOD;
                }
                //printf("%d ", f[i][j]);
            }
            //puts("");
        }

        auto go = [&](string s, int flag)
        {

            int cur = 0;
            int ret = 0;
            for (int i = 0; i < n; ++i)
            {
                for (int c = 0; c < s[i] - 'a'; ++c)
                {
                    (ret += f[n - i - 1][next[cur][c]]) %= MOD;
                }
                cur = next[cur][s[i] - 'a'];
                if (cur == m) break;
            }
            if (flag && cur != m) ret++;
            ret %= MOD;
            return ret;
        };

        int nb = go(b, 1);
        //printf("nb = %d\n", nb);
        int na = go(a, 0);
        //printf("na = %d\n", na);
        return (nb - na + MOD) % MOD;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, string s1, string s2, string evil)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.findGoodStrings(n, s1, s2, evil);
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
