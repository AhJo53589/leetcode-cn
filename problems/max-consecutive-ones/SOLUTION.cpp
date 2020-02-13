


//////////////////////////////////////////////////////////////////////////
int findMaxConsecutiveOnes(vector<int>& nums)
{
	int len = 0;
	int k = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
		{
			len = max(len, k);
			k = 0;
			continue;
		}
		k++;
	}
	return max(len, k);
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return findMaxConsecutiveOnes(nums);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

