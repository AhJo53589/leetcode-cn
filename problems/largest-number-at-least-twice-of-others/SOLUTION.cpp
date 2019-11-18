


//////////////////////////////////////////////////////////////////////////
int dominantIndex(vector<int>& nums) 
{
	if (nums.size() == 0) return -1;
	if (nums.size() == 1) return 0;
	int max = nums[0] < nums[1] ? 1 : 0;
	int second = nums[0] < nums[1] ? 0 : 1;
	for (int i = 2; i < nums.size(); i++)
	{
		if (nums[i] >= nums[max])
		{
			second = max;
			max = i;
		}
		else if (nums[i] >= nums[second])
		{
			second = i;
		}
	}
	if (nums[max] >= nums[second] * 2) return max;
	return -1;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return dominantIndex(nums);
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
	return "../../problems/largest-number-at-least-twice-of-others/tests.txt";
}

