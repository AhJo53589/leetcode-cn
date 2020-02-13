
//int lowerBound(vector<int> &nums, int target, int low, int high)
//{
//	while (low < high)
//	{
//		int mid = low + (high - low) / 2;
//		if (nums[mid] < target) low = mid + 1;
//		else high = mid;
//	}
//	return low;
//}

int lowerBound(vector<int> &nums, int target, int low, int high)
{
	if (low >= high) return low;
	int mid = low + (high - low) / 2;
	if (nums[mid] < target) return lowerBound(nums, target, mid + 1, high);
	else return lowerBound(nums, target, low, mid);
}


//////////////////////////////////////////////////////////////////////////
int search(vector<int>& nums, int target)
{
	int i = lowerBound(nums, target, 0, nums.size());
	if (i == nums.size()) return -1;
	return (nums[i] == target) ? i : -1;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int target)
{
	return search(nums,target);
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

