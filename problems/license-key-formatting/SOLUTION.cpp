
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans;
        int t = 0;
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] == '-') continue;
            ans.push_back(toupper(S[i]));
            if (++t == K) {
                t = 0;
                ans.push_back('-');
            }
        }
        if (ans.back() == '-') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string S, int K)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.licenseKeyFormatting(S, K);
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
