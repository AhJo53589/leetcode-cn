//////////////////////////////////////////////////////////////////////////
int equalSubstring(string s, string t, int maxCost)
{
	auto f_cost = [s, t](size_t i)
	{
		return abs(s[i] - t[i]);
	};

	size_t start = 0;
	int c = 0;
	int ans = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		c += f_cost(i);
		while (c > maxCost)
		{
			c -= f_cost(start++);
		}
		ans = max(ans, (int)(i - start) + 1);
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s, string t, int maxCost)
{
	return equalSubstring(s, t, maxCost);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	string s(tc.get<vector<int>>());
//	int k(tc.get<int>());
//	return removeDuplicates(nums, target);
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}


