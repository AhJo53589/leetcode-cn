
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string reverseParentheses(string s) {
        int i = 0;
        return re(s, i);
    }

    string re(string& s, int& i) {
        string str;
        for (; i < s.size(); i++) {
            if (s[i] == '(') {
                str += re(s, ++i);
            }
            else if (s[i] == ')') {
                reverse(str.begin(), str.end());
                return str;
            }
            else {
                str += s[i];
            }
        }
        return str;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.reverseParentheses(s);
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
