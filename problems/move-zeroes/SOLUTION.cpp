


//////////////////////////////////////////////////////////////////////////
void moveZeroes(vector<int>& nums)
{
	size_t j = 0;
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0) continue;
		if (i == j++) continue;
		nums[j - 1] = nums[i];
	}
	for (; j < nums.size(); j++)
	{
		nums[j] = 0;
	}
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
	moveZeroes(nums);
	return nums;
}

//#define USE_SOLUTION_CUSTOM
//void _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

