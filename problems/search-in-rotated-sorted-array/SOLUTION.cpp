
//////////////////////////////////////////////////////////////////////////
//int search(vector<int>& nums, int target) {
//	int lo = 0, hi = nums.size() - 1;
//	while (lo < hi) {
//		int mid = (lo + hi) / 2;
//		if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
//			lo = mid + 1;
//		else
//			hi = mid;
//	}
//	return lo == hi && nums[lo] == target ? lo : -1;
//}

//////////////////////////////////////////////////////////////////////////
int lowerBound(vector<int> &nums, int target, int low, int high)
{
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] == target) return mid;
		if (nums[low] <= nums[mid])
		{
			if (nums[low] <= target && target <= nums[mid])
			{
				high = mid;
			}
			else
			{
				low = mid + 1;
			}
		}
		else if (nums[mid] <= nums[high - 1])
		{
			if (nums[mid] <= target && target <= nums[high - 1])
			{
				low = mid + 1;
			}
			else
			{
				high = mid;
			}
		}
	}
	return low;
}

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
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/search-in-rotated-sorted-array/tests.txt";
}

