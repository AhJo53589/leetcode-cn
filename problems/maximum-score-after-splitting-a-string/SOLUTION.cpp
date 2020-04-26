class Solution2 {
public:
    int maxScore(string s) {
        int ans = 0;
        int c0 = 0;
        int c1 = 0;
        for (auto c : s) {
            c1 += c == '1';
        }
        for (int i = 0; i + 1 < s.size(); ++i) {
            c1 -= s[i] == '1';
            c0 += s[i] == '0';
            ans = max(ans, c0 + c1);
        }
        return ans;
    }
};
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxScore(string s) {
        vector<int> l = vector<int>(s.size(), 0);
        vector<int> r = vector<int>(s.size(), 0);
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt += (s[i] == '0');
            l[i] = cnt;
        }
        cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            cnt += (s[i] == '1');
            r[i] = cnt;
        }
        int ans = 0;
        if (s.size() == 2) {
            return l[0] + r[1];
        }
        for (int i = 1; i < s.size() - 1; i++) {
            ans = max(ans, l[i] + r[i]);
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
    return sln.maxScore(s);
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
