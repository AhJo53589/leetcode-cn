
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '?') continue;

            char left = '-';
            char right = '-';
            if (i != 0) {
                left = s[i - 1];
            }
            if (i != s.size() - 1) {
                right = s[i + 1];
            }
            if (left != 'a' && right != 'a') {
                s[i] = 'a';
            }
            else if (left != 'b' && right != 'b') {
                s[i] = 'b';
            }
            else if (left != 'c' && right != 'c') {
                s[i] = 'c';
            }
        }
        return s;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.modifyString(s);
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
