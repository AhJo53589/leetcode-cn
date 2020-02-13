


//////////////////////////////////////////////////////////////////////////
int longestSubsequence(vector<int>& arr, int difference) 
{
	int ans = 0;
	unordered_map<int, int> um;
	for (auto & n : arr)
	{
		um[n] = um[n - difference] + 1;
		ans = max(ans, um[n]);
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr, int difference)
{
	return longestSubsequence(arr,difference);
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

