
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minSwaps(string s) {
        vector<int> cnt(2, 0);
        for (auto c : s) {
            cnt[c - '0']++;
        }
        if (abs(cnt[0] - cnt[1]) > 1) return -1;

        int ans = 0;
        if (cnt[0] == cnt[1]) {
            ans = min(check(s, '0'), check(s, '1'));
        }
        else {
            char c = (cnt[0] < cnt[1]) ? '1' : '0';
            ans = check(s, c);
        }
        return ans / 2;
    }

    int check(string& s, char c) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt += (s[i] != c);
            c = (c == '0') ? '1' : '0';
        }
        return cnt;
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
    return sln.minSwaps(s);
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
