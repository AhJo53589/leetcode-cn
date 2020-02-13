


//////////////////////////////////////////////////////////////////////////
//int findLHS(vector<int>& nums) 
//{
//	sort(nums.begin(), nums.end());
//	int ans = 0;
//	map<int, int> cnt;
//	int m = INT_MIN;
//	for (auto n : nums)
//	{
//		cnt[n]++;
//		if (m != n && m != INT_MIN)
//		{
//			if (cnt.count(m - 1) != 0)
//			{
//				ans = max(ans, cnt[m] + cnt[m - 1]);
//			}
//		}
//		m = n;
//	}
//	if (m != INT_MIN && cnt.count(m - 1) != 0)
//	{
//		ans = max(ans, cnt[m] + cnt[m - 1]);
//	}
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
int findLHS(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int l = 0, ans = 0;
	for (int r = 1; r < nums.size(); ++r)
	{
		while (nums[r] - nums[l] > 1)
		{
			++l;
		}
		if (nums[r] - nums[l] == 1)
		{
			ans = max(ans, r - l + 1);
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return findLHS(nums);
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

