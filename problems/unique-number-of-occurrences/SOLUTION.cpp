//////////////////////////////////////////////////////////////////////////
bool uniqueOccurrences(vector<int>& arr)
{
	map<int, int> m;
	for (auto n : arr)
	{
		m[n]++;
	}
	unordered_set<int> s;
	for (auto k : m)
	{
		if (s.find(k.second) != s.end()) return false;
		s.insert(k.second);
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& arr)
{
	return uniqueOccurrences(arr);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//	return uniqueOccurrences(tc.get<vector<int>&>());
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}


