
//////////////////////////////////////////////////////////////////////////
//int ans(vector<int>& nums) {
//	int res = nums[0], n = nums.size();
//	vector<int> f(n, 0), g(n, 0);
//	f[0] = nums[0];
//	g[0] = nums[0];
//	for (int i = 1; i < n; ++i)
//	{
//		f[i] = max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
//		g[i] = min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
//		res = max(res, f[i]);
//	}
//	return res;
//}

//////////////////////////////////////////////////////////////////////////
//int ans(vector<int>& nums)
//{
//	if (nums.empty()) return 0;
//
//	int ans = INT_MIN;
//	int product_all = 1;
//	int product_left = 1;
//	int product_right = 0;
//	size_t start = 0;
//	bool bLeft = true;
//
//	auto f = [&](size_t i)
//	{
//		if (start == i && i == nums.size()) return;
//		if (start == i) product_all *= nums[i];
//		else if (start != i - 1)
//		{
//			product_all = (product_all < 0) ? max(product_all / product_left, product_all / product_right) : product_all;
//		}
//		ans = max(ans, product_all);
//
//		product_all = 1;
//		product_left = 1;
//		product_right = 0;
//		start = i + 1;
//		bLeft = true;
//	};
//
//	for (size_t i = 0; i < nums.size(); i++)
//	{
//		if (nums[i] == 0)
//		{
//			f(i);
//			ans = max(ans, 0);
//			continue;
//		}
//		if (nums[i] < 0)
//		{
//			product_left = bLeft ? product_left * nums[i] : product_left;
//			bLeft = false;
//			product_right = 1;
//		}
//
//		product_all *= nums[i];
//		product_left = bLeft ? product_left * nums[i] : product_left;
//		product_right *= nums[i];
//	}
//	f(nums.size());
//	return ans;
//}


//////////////////////////////////////////////////////////////////////////
int maxProduct(vector<int>& nums)
{
	int ans = INT_MIN;
	int maxTmp = 1;
	int minTmp = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] < 0)
		{
			swap(maxTmp, minTmp);
		}
		maxTmp = max(nums[i], maxTmp * nums[i]);
		minTmp = min(nums[i], minTmp * nums[i]);
		ans = max(ans, maxTmp);
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return maxProduct(nums);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
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
	return "../../problems/maximum-product-subarray/tests.txt";
}

