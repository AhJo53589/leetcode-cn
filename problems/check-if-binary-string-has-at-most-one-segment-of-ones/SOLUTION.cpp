
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool checkOnesSegment(string s) {
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            ans += (s[i] != s[i - 1]);
        }
        return ans <= 1;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.checkOnesSegment(s);
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
