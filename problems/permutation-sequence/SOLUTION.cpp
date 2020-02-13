
//////////////////////////////////////////////////////////////////////////
//void getPermutation(vector<int> &nums)
//{
//	if (nums.empty()) return;
//
//	vector<int> vec;
//	for (size_t i = nums.size() - 1; i > 0;)
//	{
//		i--;
//		vec.push_back(nums[i + 1]);
//		if (nums[i] < nums[i + 1])
//		{
//			sort(vec.begin(), vec.end());
//			auto it = lower_bound(vec.begin(), vec.end(), nums[i]);
//			swap(nums[i], *it);
//			for (size_t j = 0; j < vec.size(); j++)
//			{
//				nums[j + i + 1] = vec[j];
//			}
//			break;
//		}
//	}
//}
//
//string getPermutation(int n, int k)
//{
//	vector<int> nums;
//	for (int i = 0; i < n; i++)
//	{
//		nums.push_back(i + 1);
//	}
//	while (--k > 0)
//	{
//		getPermutation(nums);
//	}
//	string ans;
//	for (auto &n : nums)
//	{
//		ans += to_string(n);
//	}
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
int factorial(unordered_map<int, int> &fac, int k)
{
	if (k < 2) return 1;
	if (fac.count(k)) return fac[k];
	int f = k * factorial(fac, k - 1);
	fac[k] = f;
	return f;
}

void getPermutation(vector<int> &nums, int len, unordered_map<int, int> &fac, int k)
{
	if (k == 0 || len == 0) return;

	int f = factorial(fac, len - 1);
	if (k < f)
	{
		getPermutation(nums, len - 1, fac, k);
	}
	else
	{
		int i = nums.size() - len;
		int j = k / f;
		k -= j * f;

		for (j = min(i + j, (int)nums.size() - 1); j > i; j--)
		{
			swap(nums[j], nums[j - 1]);
		}
		getPermutation(nums, len - 1, fac, k);
	}
}


//////////////////////////////////////////////////////////////////////////
string getPermutation(int n, int k)
{
	vector<int> nums;
	for (int i = 0; i < n; i++)
	{
		nums.push_back(i + 1);
	}

	unordered_map<int, int> fac;
	getPermutation(nums, nums.size(), fac, k - 1);

	string ans;
	for (auto &n : nums)
	{
		ans += to_string(n);
	}
	return ans;
}


//////////////////////////////////////////////////////////////////////////
string _solution_run(int n, int k)
{
	return getPermutation(n,k);
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

