


//////////////////////////////////////////////////////////////////////////
int pivotIndex(vector<int>& nums) 
{
	if (nums.size() == 0) return -1;
	int sum_l = 0;
	int sum_r = 0;
	for (auto i : nums) sum_r += i;
	for (int i = 0; i < nums.size(); i++)
	{
		sum_r -= nums[i];
		if (sum_l == sum_r) return i;
		sum_l += nums[i];
	}
	return -1;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return pivotIndex(nums);
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

