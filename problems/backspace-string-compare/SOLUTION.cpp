
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string ans_s;
        string ans_t;
        for (int i = 0; i < 2; i++) {
            string& ans = (i == 0) ? ans_s : ans_t;
            string& X = (i == 0) ? S : T;

            for (auto c : X) {
                if (c == '#') {
                    if (!ans.empty()) {
                        ans.pop_back();
                    }
                }
                else {
                    ans.push_back(c);
                }
            }
        }
        return ans_s == ans_t;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string S, string T)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.backspaceCompare(S, T);
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
