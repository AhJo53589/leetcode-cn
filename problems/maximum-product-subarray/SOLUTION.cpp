
//////////////////////////////////////////////////////////////////////////
int maxProduct(vector<int>& nums)
{
	int ans = INT_MIN;
	int maxP = 1;
	int minP = 1;
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] < 0)
		{
			swap(maxP, minP);
		}
		maxP = max(maxP * nums[i], nums[i]);
		minP = min(minP * nums[i], nums[i]);
		ans = max(ans, maxP);
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return maxProduct(nums);
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

