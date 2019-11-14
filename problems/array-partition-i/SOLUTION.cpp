


//////////////////////////////////////////////////////////////////////////
int arrayPairSum(vector<int>& nums)
{
	int sum = 0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i += 2)
	{
		sum += min(nums[i], nums[i + 1]);
	}
	return sum;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return arrayPairSum(nums);
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
	return "../../problems/array-partition-i/tests.txt";
}

