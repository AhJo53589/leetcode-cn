
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto& s : words) {
            if (check(s)) return s;
        }
        return "";
    }

    bool check(string& s) {
        int i = 0;
        int j = (int)s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<string>& words)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.firstPalindrome(words);
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
