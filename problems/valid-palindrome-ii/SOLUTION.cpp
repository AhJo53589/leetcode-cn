
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool validPalindrome(string s) {
        return valid(s, 0, s.size() - 1, 0);
    }

    bool valid(string& s, int l, int r, int del) {
        if (l >= r) return true;

        if (s[l] != s[r]) {
            del++;
            if (del > 1) return false;
            return (valid(s, l + 1, r, del) || valid(s, l, r - 1, del));
        }

        return valid(s, l + 1, r - 1, del);
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.validPalindrome(s);
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
