
//int findDuplicate(vector<int>& nums)
//{
//	unordered_set<int> s;
//	for (auto i : nums)
//	{
//		if (s.count(i)) return i;
//		s.insert(i);
//	}
//	return nums[0];
//}

//////////////////////////////////////////////////////////////////////////
int findDuplicate(vector<int>& nums) {
	int low = nums[0];
	int fast = nums[nums[0]];
	while (low != fast)
	{
		low = nums[low];
		fast = nums[nums[fast]];
	}
	low = 0;
	while (low != fast)
	{
		low = nums[low];
		fast = nums[fast];
	}
	return fast;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return findDuplicate(nums);
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

