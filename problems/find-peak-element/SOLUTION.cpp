


//////////////////////////////////////////////////////////////////////////
int findPeakElement(vector<int>& nums)
{
	int low = 0;
	int high = nums.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		bool l = (mid == 0 || nums[mid - 1] < nums[mid]);
		bool r = (mid == nums.size() - 1 || nums[mid + 1] < nums[mid]);
		if (l && r) return mid;
		else if (l) low = mid + 1;
		else high = mid;
	}
	return (low < nums.size()) ? low : -1;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return findPeakElement(nums);
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
	return "../../problems/find-peak-element/tests.txt";
}

