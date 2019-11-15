
//////////////////////////////////////////////////////////////////////////
//int findLengthOfLCIS(vector<int>& nums)
//{
//	if (nums.size() == 0) return 0;
//	vector<int> dp(nums.size(), 1);
//	int ans = 1;
//	for (int i = 1; i < nums.size(); i++)
//	{
//		if (nums[i] > nums[i - 1])
//		{
//			dp[i] = dp[i - 1] + 1;
//			ans = max(ans, dp[i]);
//		}
//	}
//	return ans;
//}


//////////////////////////////////////////////////////////////////////////
int findLengthOfLCIS(vector<int>& nums)
{
	if (nums.size() == 0) return 0;
	int ans = 1;
	int temp = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] > nums[i - 1])
		{
			temp++;
			ans = max(ans, temp);
		}
		else
		{
			temp = 1;
		}
	}
	return ans;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return findLengthOfLCIS(nums);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/longest-continuous-increasing-subsequence/tests.txt";
}

