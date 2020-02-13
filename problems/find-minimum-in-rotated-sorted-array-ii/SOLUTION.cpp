


//////////////////////////////////////////////////////////////////////////
int findMin(vector<int>& nums)
{
	int low = 0;
	int high = nums.size() - 1;
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] == nums[high]) high--;
		else if (nums[mid] > nums[high]) low = mid + 1;
		//else if (nums[mid] < nums[0]) high = mid;
		else high = mid;
	}
	return (low < nums.size()) ? nums[low] : nums[0];
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return findMin(nums);
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

