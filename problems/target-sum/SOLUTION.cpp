
//int findTargetSumWays(vector<int>& nums, int S) {
//	int sum = 0;
//	for (int n : nums) sum += n;
//	if (sum < S || (S + sum) % 2 != 0) return 0;
//	int right = (S + sum) >> 1;	// int right = (S + sum) / 2;
//	vector<int> dp(right + 1, 0);
//	dp[0] = 1;
//	for (int d : nums) {
//		for (int i = right; i >= d; i--) dp[i] += dp[i - d];
//	}
//	return dp[right];
//}

int findTargetSumWays(vector<int>& nums, int S, int iIndex, int iSum)
{
	if (iIndex == nums.size() - 1)
	{
		if (nums[iIndex] == 0 && iSum == S) return 2;
		if (iSum + nums[iIndex] == S) return 1;
		if (iSum - nums[iIndex] == S) return 1;
		return 0;
	}

	int iRst = 0;
	iRst += findTargetSumWays(nums, S, iIndex + 1, iSum + nums[iIndex]);
	iRst += findTargetSumWays(nums, S, iIndex + 1, iSum - nums[iIndex]);
	return iRst;
}

//////////////////////////////////////////////////////////////////////////
int findTargetSumWays(vector<int>& nums, int S)
{
	return findTargetSumWays(nums, S, 0, 0);
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int S)
{
	return findTargetSumWays(nums,S);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

