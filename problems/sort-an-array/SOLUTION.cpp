
//////////////////////////////////////////////////////////////////////////
size_t partition(vector<int>& nums, size_t left, size_t right)
{
	size_t mid = left;
	for (auto i = left; i < right; i++)
	{
		if (nums[i] < nums[right - 1])
		{
			swap(nums[i], nums[mid++]);
		}
	}
	swap(nums[mid], nums[right - 1]);
	return mid;
}

void quickSort(vector<int>& nums, size_t left, size_t right)
{
	if (left >= right) return;
	size_t mid = partition(nums, left, right);
	quickSort(nums, left, mid);
	quickSort(nums, mid + 1, right);
}


//////////////////////////////////////////////////////////////////////////
vector<int> sortArray(vector<int>& nums)
{
	quickSort(nums, 0, nums.size());
	return nums;
}


//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
	return sortArray(nums);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
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
	return "../../problems/sort-an-array/tests.txt";
}

