
//////////////////////////////////////////////////////////////////////////
//void nextPermutation(vector<int>& nums)
//{
//	if (next_permutation(nums.begin(), nums.end())) return;
//	sort(nums.begin(), nums.end());
//}

//////////////////////////////////////////////////////////////////////////
//void nextPermutation(vector<int>& nums) 
//{
//	if (nums.empty()) return;
//
//	int i;
//	for (i = nums.size() - 1; i > 0 && nums[i - 1] >= nums[i]; i--);
//
//	reverse(nums.begin() + i, nums.end());
//	if (i-- != 0) 
//	{
//		auto it = upper_bound(nums.begin() + i, nums.end(), nums[i]);
//		swap(nums[i], *it);
//	}
//}


//////////////////////////////////////////////////////////////////////////
void nextPermutation(vector<int>& nums)
{
	if (nums.empty()) return;

	vector<int> vec;
	bool bEndFlag = true;
	for (size_t i = nums.size() - 1; i > 0;)
	{
		i--;
		vec.push_back(nums[i + 1]);
		if (nums[i] < nums[i + 1])
		{
			bEndFlag = false;
			sort(vec.begin(), vec.end());
			auto it = upper_bound(vec.begin(), vec.end(), nums[i]);
			swap(nums[i], *it);
			for (size_t j = 0; j < vec.size(); j++)
			{
				nums[j + i + 1] = vec[j];
			}
			break;
		}
	}

	if (bEndFlag)
	{
		sort(nums.begin(), nums.end());
	}
}


//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
	nextPermutation(nums);
	return nums;
}

//#define USE_SOLUTION_CUSTOM
//void _solution_custom(TestCases &tc)
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
	return "../../problems/next-permutation/tests.txt";
}

