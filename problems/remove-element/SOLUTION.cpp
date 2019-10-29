


//////////////////////////////////////////////////////////////////////////
int removeElement(vector<int>& nums, int val)
{
	int len = 0;
	int low = 0;
	int high = nums.size() - 1;

	while (low <= high)
	{
		if (nums[low] == val) swap(nums[low], nums[high--]);
		else low++;
	}

	return low;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int val)
{
	return removeElement(nums,val);
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
	return "../../problems/remove-element/tests.txt";
}

