
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
	{
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 0; i <= target; i++)
		{
			for (int j = 0; j < nums.size(); j++)
			{
				if (i < nums[j]) continue;
                dp[i] = (dp[i] >= INT_MAX - dp[i - nums[j]]) ? INT_MAX : dp[i] + dp[i - nums[j]];
			}
		}
		return dp[target];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int target)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.combinationSum4(nums, target);
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
