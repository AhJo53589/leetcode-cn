


//////////////////////////////////////////////////////////////////////////
int searchInsert(vector<int>& nums, int target)
{
	size_t low = 0;
	size_t high = nums.size();
	while (low < high)
	{
		size_t mid = low + (high - low) / 2;
		if (nums[mid] < target)
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}
	return low;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int target)
{
	return searchInsert(nums,target);
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

