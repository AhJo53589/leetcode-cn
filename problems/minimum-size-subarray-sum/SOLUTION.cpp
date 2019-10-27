


//////////////////////////////////////////////////////////////////////////
int minSubArrayLen(int s, vector<int>& nums)
{
	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return nums[0] >= s ? 1 : 0;

	int iLen_min = INT_MAX;
	int low = 0;
	int high = 1;
	int sum = nums[low] + nums[high];
	while (low < nums.size() - 1)
	{
		if (nums[low] >= s) return 1;
		if (sum >= s)
		{
			iLen_min = min(iLen_min, high - low + 1);
			sum -= nums[low];
			low++;
		}
		else
		{
			high++;
			if (high == nums.size()) break;
			sum += nums[high];
		}
	}
	return iLen_min == INT_MAX ? 0 : iLen_min;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int s, vector<int>& nums)
{
	return minSubArrayLen(s,nums);
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
	return "../../problems/minimum-size-subarray-sum/tests.txt";
}

