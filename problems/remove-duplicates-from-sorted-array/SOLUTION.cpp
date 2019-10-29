
//int removeDuplicates(vector<int>& nums)		// 20ms
//{
//	if (nums.size() == 0) return 0;
//	auto i = 0;
//	auto j = 0;
//	while (j < nums.size()) 
//	{
//		if (nums[i] == nums[j])
//			j++;
//		else
//			nums[++i] = nums[j];
//	}
//	return i + 1;
//}

//////////////////////////////////////////////////////////////////////////
int removeDuplicates(vector<int>& nums)	// 32ms
{
	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return 1;

	int iNewLen = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] != nums[iNewLen])
		{
			++iNewLen;
			if (iNewLen != i)
			{
				nums[iNewLen] = nums[i];
			}
		}
	}
	return iNewLen + 1;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return removeDuplicates(nums);
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
	return "../../problems/remove-duplicates-from-sorted-array/tests.txt";
}

