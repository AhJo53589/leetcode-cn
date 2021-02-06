
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimumLength(string s) {
        return dfs(s, 0, s.size() - 1);
    }

    int dfs(string& s, int l, int r) {
        if (l == r) return 1;
        if (s[l] != s[r]) return r - l + 1;

        int ll = l;
        while (ll < s.size() && s[ll] == s[l]) {
            ll++;
        }
        int rr = r;
        while (s[rr] == s[r] && rr > ll) {
            rr--;
        }
        return dfs(s, ll, rr);
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
    return sln.minimumLength(s);
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
