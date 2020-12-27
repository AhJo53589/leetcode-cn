
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowel = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
        vector<int> cnt(2);
        for (int i = 0; i < s.size(); i++) {
            int idx = (i >= s.size() / 2);
            cnt[idx] += (vowel.find(s[i]) != vowel.end());
        }
        return cnt[0] == cnt[1];
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.halvesAreAlike(s);
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
