
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> dp(2, 1);
        for (int i = 1; i < nums.size(); i++) {
            dp[0] = (nums[i] < nums[i - 1]) ? max(dp[0], dp[1] + 1) : dp[0];
            dp[1] = (nums[i] > nums[i - 1]) ? max(dp[1], dp[0] + 1) : dp[1];
        }
        return nums.empty() ? 0 : max(dp[0], dp[1]);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.wiggleMaxLength(nums);
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
