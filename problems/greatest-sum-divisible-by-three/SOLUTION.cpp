


//////////////////////////////////////////////////////////////////////////
int maxSumDivThree(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());

	vector<vector<int>> a(2, vector<int>());
    int ans = 0;
    for (auto n : nums)
    {
		ans += n;
		if ((n % 3) == 0 || a[(n % 3) - 1].size() == 2) continue;
		a[(n % 3) - 1].push_back(n);
	}

	if (ans % 3 != 0)
	{
		int k1 = (ans % 3) - 1;
		int k2 = (k1 == 0) ? 1 : 0;
		int t1 = a[k1].empty() ? INT_MAX : a[k1][0];
		int t2 = a[k2].size() < 2 ? INT_MAX : a[k2][0] + a[k2][1];
		ans -= min(t1, t2);
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return maxSumDivThree(nums);
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

