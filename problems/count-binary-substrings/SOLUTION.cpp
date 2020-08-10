
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countBinarySubstrings(string s) {
        s += '-';
        int ans = 0;
        char last = '-';
        int cnt_pre = 0;
        int cnt_cur = 0;
        for (auto c : s) {
            if (last != c) {
                last = c;
                ans += min(cnt_pre, cnt_cur);
                cnt_pre = cnt_cur;
                cnt_cur = 0;
            }
            cnt_cur++;
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
	return sln.countBinarySubstrings(s);
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
