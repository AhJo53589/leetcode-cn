
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < t.size(); j++) {
                int diff = 0;
                for (int k = 0; i + k < s.size() && j + k < t.size() && diff < 2; k++) {
                    diff += (s[i + k] != t[j + k]);
                    ans += (diff == 1);
                }
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s, string t)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.countSubstrings(s, t);
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
