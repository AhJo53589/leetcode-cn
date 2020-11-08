
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        vector<vector<int>> pos(26, vector<int>(2, -1));
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            pos[c][1] = (pos[c][0] != -1) ? i : pos[c][1];
            pos[c][0] = (pos[c][0] == -1) ? i : pos[c][0];
            ans = (pos[c][1] != -1) ? max(ans, pos[c][1] - pos[c][0] - 1) : ans;
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
	return sln.maxLengthBetweenEqualCharacters(s);
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
