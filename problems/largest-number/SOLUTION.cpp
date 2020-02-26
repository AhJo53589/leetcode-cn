
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
	string largestNumber(vector<int>& nums)
	{
		auto f_sort = [](const int& a, const int& b)
		{
			long long n_a = 10;
			while (a / n_a) n_a *= 10;
			long long n_b = 10;
			while (b / n_b) n_b *= 10;
			long long r_a = (long long)a * n_b + (long long)b;
			long long r_b = (long long)b * n_a + (long long)a;
			return r_a < r_b;
		};

		sort(nums.rbegin(), nums.rend(), f_sort);

		string ans;
		for (auto n : nums)
		{
			ans = (ans == "0") ? to_string(n) : ans + to_string(n);
		}
		return ans;
	}
};


//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	string largestNumber(vector<int>& nums)
	{
		if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) return string("0");

		vector<string> strNums(nums.size());
		std::transform(nums.begin(), nums.end(), strNums.begin(), [](int x) { return std::to_string(x);	});

		std::sort(strNums.rbegin(), strNums.rend(), [](const string& a, const string& b) { return a + b < b + a; });

		return std::accumulate(strNums.begin(), strNums.end(), string());
	}
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<int>& nums)
{
	Solution sln;
	return sln.largestNumber(nums);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

