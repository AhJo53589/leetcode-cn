
//int lowerBound(vector<int> &nums, int target, int low, int high)
//{
//	if (low >= high) return low;
//	int mid = low + (high - low) / 2;
//	if (nums[mid] < target) return lowerBound(nums, target, mid + 1, high);
//	else return lowerBound(nums, target, low, mid);
//}

int lowerBound(vector<int> &nums, int target, int low, int high)
{
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] < target) low = mid + 1;
		else high = mid;
	}
	return low;
}



//////////////////////////////////////////////////////////////////////////
vector<int> searchRange(vector<int>& nums, int target)
{
	int l = lowerBound(nums, target, 0, nums.size());
	if (l < nums.size() && nums[l] == target)
	{
		int r = lowerBound(nums, target + 1, l, nums.size());
		return { l, r - 1 };
	}
	return { -1,-1 };
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums, int target)
{
	return searchRange(nums,target);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

