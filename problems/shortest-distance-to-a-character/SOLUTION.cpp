
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size(), INT_MAX);
        int a = s.size();
        for (int i = 0; i < s.size(); i++) {
            a = (s[i] == c) ? 0 : a + 1;
            for (int j = 0; i - j >= 0 && ans[i - j] > a + j; j++) {
                ans[i - j] = a + j;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(string s, char c)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.shortestToChar(s, c);
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
