
//////////////////////////////////////////////////////////////////////////
//string largestNumber(vector<int>& nums)
//{
//	auto f_sort = [](const int &a, const int &b)
//	{
//		long long n_a = 10;
//		while (a / n_a) n_a *= 10;
//		long long n_b = 10;
//		while (b / n_b) n_b *= 10;
//		long long r_a = (long long)a * n_b + (long long)b;
//		long long r_b = (long long)b * n_a + (long long)a;
//		return r_a < r_b;
//	};
//
//	sort(nums.rbegin(), nums.rend(), f_sort);
//
//	string ans;
//	for (auto n : nums)
//	{
//		ans = (ans == "0") ? to_string(n) : ans + to_string(n);
//	}
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
string largestNumber(vector<int>& nums)
{
	sort(nums.rbegin(), nums.rend(), [](const int& a, const int& b)
	{
		string sa = to_string(a);
		string sb = to_string(b);
		return sa + sb < sb + sa;
	});

	string ans;
	for (auto n : nums)
	{
		ans = (ans == "0") ? to_string(n) : ans + to_string(n);
	}
	return ans;
}


//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<int>& nums)
{
	return largestNumber(nums);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/largest-number/tests.txt";
}

