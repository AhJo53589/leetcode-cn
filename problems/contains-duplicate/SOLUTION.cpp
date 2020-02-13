
//bool containsDuplicate(vector<int>& nums) 
//{
//	map<int, int> a;
//	for (int i : nums)
//	{
//		a[i]++;
//		if (a[i] > 1) return true;
//	}
//	return false;
//}

//////////////////////////////////////////////////////////////////////////
bool containsDuplicate(vector<int>& nums)
{
	sort(nums.begin(), nums.end());

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i - 1] == nums[i]) return true;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums)
{
	return containsDuplicate(nums);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

