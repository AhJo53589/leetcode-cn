


//////////////////////////////////////////////////////////////////////////
vector<int> countSmaller(vector<int>& nums)
{
	if (nums.empty()) return {};
	if (nums.size() == 1) return { 0 };

	vector<int> counts(nums.size(), 0);
	vector<int> sort_nums;

	sort_nums.push_back(nums[nums.size() - 1]);
	size_t i = nums.size() - 2;
	do
	{
		auto it = lower_bound(sort_nums.begin(), sort_nums.end(), nums[i]);
		counts[i] = it - sort_nums.begin();
		sort_nums.insert(it, nums[i]);
	} while (i-- != 0);

	return counts;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
	return countSmaller(nums);
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

