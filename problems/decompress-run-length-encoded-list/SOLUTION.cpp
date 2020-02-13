


//////////////////////////////////////////////////////////////////////////
vector<int> decompressRLElist(vector<int>& nums)
{
	vector<int> ans;
	for (size_t i = 0; i < nums.size(); i += 2)
	{
		for (size_t j = 0; j < nums[i]; j++)
		{
			ans.push_back(nums[i + 1]);
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
	return decompressRLElist(nums);
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

