
//////////////////////////////////////////////////////////////////////////
//string largestNumber(vector<int>& nums)
//{
//	auto f_sort = [](const string &a, const string &b)
//	{
//		string r_a = a + b;
//		string r_b = b + a;
//		int i = 0;
//		do
//		{
//			if (r_a[i] == r_b[i]) continue;
//			return (r_a[i] - '0' < r_b[i] - '0');
//		} while (++i < r_a.size());
//		return (r_a[0] - '0' < r_b[0] - '0');
//	};
//
//	vector<string> str;
//	for (auto &n : nums)
//	{
//		str.push_back(to_string(n));
//	}
//	sort(str.rbegin(), str.rend(), f_sort);
//
//	string ans;
//	bool bZeroFlag = true;
//	for (auto &s : str)
//	{
//		if (bZeroFlag)
//		{
//			if (s == "0") continue;
//			bZeroFlag = false;
//		}
//		ans.append(s);
//	}
//	return ans.empty() ? "0" : ans;
//}


//////////////////////////////////////////////////////////////////////////
string largestNumber(vector<int>& nums)
{
	auto f_sort = [](const int &a, const int &b)
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
	bool bZeroFlag = true;
	for (auto &n : nums)
	{
		if (bZeroFlag)
		{
			if (n == 0) continue;
			bZeroFlag = false;
		}
		ans.append(to_string(n));
	}
	return ans.empty() ? "0" : ans;
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

