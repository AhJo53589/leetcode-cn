
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), 0);
        for (int i = 0; i < dp.size(); i++) {
            int next = i + 1;
            if (next < dp.size()) {
                dp[next] = max(dp[next], dp[i]);
            }

            next = i + questions[i][1] + 1;
            dp[i] += questions[i][0];
            if (next < dp.size()) {
                dp[next] = max(dp[next], dp[i]);
            }
        }
        auto ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
long _solution_run(vector<vector<int>>& questions)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.mostPoints(questions);
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
