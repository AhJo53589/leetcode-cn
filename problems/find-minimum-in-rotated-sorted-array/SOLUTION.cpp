
//int findMin(vector<int>& nums) {
//	int lens = nums.size();
//	int i = 0;
//	int j = lens - 1;
//	while (i < j)
//	{
//		int mid = i + (j - i) / 2;
//		if (nums[mid] > nums[j])
//		{
//			i = mid + 1;
//		}
//		else
//		{
//			j = mid;
//		}
//	}
//	return nums[i];
//}

//////////////////////////////////////////////////////////////////////////
int findMin(vector<int>& nums)
{
	if (nums.empty()) return -1;
	if (nums.size() == 1) return nums[0];
	int low = 0;
	int high = nums.size();
	if (low == 0 && nums[low] < nums[nums.size() - 1]) return nums[low];
	if (high - 2 != 0 && high - 1 != 0 && nums[high - 1] < nums[high - 2]) return nums[high - 1];
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (low != 0 && nums[low] < nums[low - 1]) return nums[low];
		if (mid != 0 && nums[mid] < nums[mid - 1]) return nums[mid];
		if (nums[low] <= nums[mid]) low = mid + 1;
		//else if (nums[mid] <= nums[high - 1]) high = mid;
		else high = mid;
	}
	return (low < nums.size()) ? nums[low] : -1;
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
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/find-minimum-in-rotated-sorted-array/tests.txt";
}

