
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool checkZeroOnes(string s) {
        vector<int> cnt(3);
        for (int i = 1; i <= s.size(); i++) {
            if (i != s.size() && s[i] == s[i - 1]) {
                cnt[2]++;
            }
            else {
                int last = s[i - 1] - '0';
                cnt[last] = max(cnt[last], cnt[2] + 1);
                cnt[2] = 0;
            }
        }
        return cnt[0] < cnt[1];
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    cout << s << endl;

    Solution sln;
    return sln.checkZeroOnes(s);
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
