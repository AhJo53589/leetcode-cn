


//////////////////////////////////////////////////////////////////////////
int firstMissingPositive(vector<int>& nums)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] >= 1 && nums[i] < nums.size())
		{
			int t = nums[i] - 1;
			if (nums[i] != nums[t])
			{
				swap(nums[i], nums[t]);
				i -= (t > i);


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return firstMissingPositive(nums);
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

