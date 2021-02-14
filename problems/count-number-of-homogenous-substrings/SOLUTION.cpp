
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countHomogenous(string s) {
        vector<map<int, int>> dic(26);
        for (int i = 0; i < s.size(); ) {
            int t = 1;
            for (int j = i + 1; j < s.size() && s[i] == s[j]; j++) {
                t++;
            }
            for (int k = t; k >= 1; k--) {
                dic[s[i] - 'a'][k] += (t - k) + 1;
            }
            i += t;
        }

        long long mod = 1e9 + 7;
        long long ans = 0;
        for (int i = 0; i < dic.size(); i++) {
            for (auto [t, cnt] : dic[i]) {
                ans += cnt;
                ans %= mod;
            }
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
    cout << s << endl;
    Solution sln;
    return sln.countHomogenous(s);
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
