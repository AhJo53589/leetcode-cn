
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) return false;
        vector<int> vi(26, 0);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans = max(ans, getCount(s[i], t[i], vi));
        }
        return ans <= k;
    }

    int getCount(char a, char b, vector<int>& vi) {
        if (a == b) return 0;
        int df = ((b - 'a' + 26) - (a - 'a')) % 26;
        int cnt = df + vi[df] * 26;
        vi[df]++;
        return cnt;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s, string t, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << s << endl;
    cout << t << endl;
    cout << k << endl;
    Solution sln;
    return sln.canConvertString(s, t, k);
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
