
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        vector<int> dp(sentence.size() + 1, 0);

        for (int i = 0; i < sentence.size(); i++) {
            dp[i + 1] = (i == 0) ? i + 1 : min(i + 1, dp[i] + 1);

            for (auto& w : dictionary) {
                if (i + 1 < w.size()) continue;
                if (memcmp(&sentence[i + 1 - w.size()], &w[0], w.size()) == 0) {
                    dp[i + 1] = min(dp[i + 1], dp[i + 1 - w.size()]);
                }
            }
        }

        return dp.back();
    }
};
//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& dictionary, string sentence)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.respace(dictionary, sentence);
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
