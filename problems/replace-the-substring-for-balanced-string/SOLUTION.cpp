//////////////////////////////////////////////////////////////////////////
int balancedString(string s) 
{
	int ans = s.size();
	int n = s.size() / 4;
	unordered_map<char, int> um_count;
	unordered_map<char, int> um_replace;
	auto f_check = [&um_count, &um_replace, n]()
	{
		return (um_count['Q'] - um_replace['Q'] <= n
			&& um_count['W'] - um_replace['W'] <= n
			&& um_count['E'] - um_replace['E'] <= n
			&& um_count['R'] - um_replace['R'] <= n);
	};

	for (auto c : s)
	{
		um_count[c]++;
	}

	int i = 0, j = 0;
	while (i < s.size())
	{
		while (j < s.size() && !f_check())
		{
			um_replace[s[j++]]++;
		}
		if (f_check())
		{
			ans = min(ans, j - i);
		}
		um_replace[s[i++]]--;
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	return balancedString(s);
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


