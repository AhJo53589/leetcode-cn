


//////////////////////////////////////////////////////////////////////////
vector<int> replaceElements(vector<int>& arr)
{
	for (size_t i = 0; i < arr.size() - 1; i++)
	{
		int t = INT_MIN;
		for (size_t j = i + 1; j < arr.size(); j++)
		{
			t = max(t, arr[j]);
		}
		arr[i] = t;
	}
	arr.back() = -1;
	return arr;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& arr)
{
	return replaceElements(arr);
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

