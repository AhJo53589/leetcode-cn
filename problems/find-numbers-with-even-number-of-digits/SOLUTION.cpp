


//////////////////////////////////////////////////////////////////////////
int findNumbers(vector<int>& nums) 
{
	int ans = 0;
	for (auto n : nums)
	{
		string str = to_string(n);
		ans += ((str.size() % 2) == 0);
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return findNumbers(nums);
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
	return "../../problems/find-numbers-with-even-number-of-digits/tests.txt";
}

