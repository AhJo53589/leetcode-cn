
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue)
    {
        vector<int> dp(stoneValue.size(), INT_MIN);
        for (int i = stoneValue.size() - 1; i >= 0; i--)
        {
            int s = 0;
            for (int j = 0; j < 3 && i + j + 1 <= stoneValue.size(); j++)
            {
                s += stoneValue[i + j];
                dp[i] = (i + j + 1 == stoneValue.size()) ? max(dp[i], s) : dp[i] = max(dp[i], s - dp[i + j + 1]);
            }
        }

        if (dp[0] == 0) return "Tie";
        return (dp[0] > 0) ? "Alice" : "Bob";
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<int>& stoneValue)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(stoneValue);

    Solution sln;
    return sln.stoneGameIII(stoneValue);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
