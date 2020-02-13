


//////////////////////////////////////////////////////////////////////////
int minSetSize(vector<int>& arr) 
{
	map<int, int> cnt;
	for (auto &n : arr)
	{
		cnt[n]++;
	}

	vector<int> v;
	for (auto &m : cnt)
	{
		v.push_back(m.second);
	}
	sort(v.rbegin(), v.rend());

	int sum = arr.size() / 2;
	for (int i = 0; i < v.size(); i++)
	{
		sum -= v[i];
		if (sum <= 0) return i + 1;
	}
	return -1;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr)
{
	return minSetSize(arr);
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

