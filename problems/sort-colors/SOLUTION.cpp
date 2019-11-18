


//////////////////////////////////////////////////////////////////////////
void sortColors(vector<int>& nums)
{
	int low = 0;
	int high = nums.size() - 1;
	while (low < nums.size() && nums[low] == 0) low++;
	while (high > low && nums[high] == 2) high--;
	for (int i = 0; i < nums.size(); i++)
	{
		auto swap = [](int &a, int &b) {if (a == b) return; a ^= b; b ^= a; a ^= b; };
		if (i > low && nums[i] == 0) swap(nums[i--], nums[low++]);
		else if (i < high && nums[i] == 2) swap(nums[i--], nums[high--]);
	}
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
	sortColors(nums);
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
	return "../../problems/sort-colors/tests.txt";
}

