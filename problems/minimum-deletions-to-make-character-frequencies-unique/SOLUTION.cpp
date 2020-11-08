
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26, 0);
        for (auto c : s) {
            cnt[c - 'a']++;
        }
        sort(cnt.rbegin(), cnt.rend());

        int ans = 0;
        int st = INT_MAX;
        for (auto c : cnt) {
            if (c == 0) break;
            ans += (c > st) ? c - st : 0;
            st = min(st, c);
            st = max(0, st - 1);
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
    return sln.minDeletions(s);
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
