
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int massage(vector<int>& nums) 
    {
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            int a = (i - 3 < 0) ? 0 : dp[i - 3];
            int b = (i - 2 < 0) ? 0 : dp[i - 2];
            dp[i] = max(a, b) + nums[i];
        }
        return dp.empty() ? 0 : *max_element(dp.begin(), dp.end());
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.massage(nums);
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
