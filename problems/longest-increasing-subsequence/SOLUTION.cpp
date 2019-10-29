
//////////////////////////////////////////////////////////////////////////
//int lengthOfLIS(vector<int>& nums)
//{
//	if (nums.size() == 0) return 0;
//	vector<int> log(nums.size(), INT_MAX);
//	int out = 0;
//	for (int pos = 0; pos < nums.size(); pos++)
//	{
//		int pos1 = 0, pos2 = nums.size() - 1;
//		while (pos2 > pos1)
//		{
//			int mid = (pos1 + pos2) / 2;
//			if (log[mid] >= nums[pos]) pos2 = mid;
//			else pos1 = mid + 1;
//		}
//		log[pos1] = nums[pos];
//		out = max(out, pos1 + 1);
//	}
//	return out;
//}

//////////////////////////////////////////////////////////////////////////
int lengthOfLIS(vector<int>& nums)
{
	if (nums.empty()) return 0;
	int res = 0;
	vector<int> dp(nums.size(), 0);
	for (int i = 1; i < nums.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				res = max(res, dp[i]);
			}
		}
	}
	return res + 1;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return lengthOfLIS(nums);
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
	return "../../problems/longest-increasing-subsequence/tests.txt";
}

