
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int mod = 1e9 + 7;
        int ans = 0;

        map<int, int> cnt;
        for (auto d : deliciousness) {
            cnt[d]++;
        }

        for (const auto& [k, v] : cnt) {
            for (int x = 1; x <= (1 << 21); x *= 2) {
                int nk = x - k;
                if (nk < k) continue;
                if (cnt.find(nk) == cnt.end()) continue;
                if (nk == k) {
                    ans += 1LL * v * (v - 1) / 2 % mod;
                }
                else {
                    ans += 1LL * cnt[nk] * cnt[k] % mod;
                }
                ans %= mod;
            }
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& deliciousness)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.countPairs(deliciousness);
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
