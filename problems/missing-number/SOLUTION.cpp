
//int missingNumber(vector<int>& nums)
//{
//	//int sum = (0 + nums.size() - 1 + 1) * (nums.size() + 1) / 2;
//	int sum = nums.size() * (nums.size() + 1) / 2;
//	for (auto i : nums) sum -= i;
//	return sum;
//}

//////////////////////////////////////////////////////////////////////////
int missingNumber(vector<int>& nums)
{
	int missing = nums.size(); 
	for (int i = 0; i < nums.size(); i++)
	{ 
		missing ^= i ^ nums[i]; 
	} 
	return missing;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return missingNumber(nums);
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

