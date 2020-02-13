


//////////////////////////////////////////////////////////////////////////
int findContentChildren(vector<int>& g, vector<int>& s)
{
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());

	int ans = 0;
	size_t j = 0;
	for (size_t i = 0; i < g.size(); i++)
	{
		while (j < s.size() && g[i] > s[j]) j++;
		if (j == s.size()) break;
		ans++;
		j++;
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& g, vector<int>& s)
{
	return findContentChildren(g,s);
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

