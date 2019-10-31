
//////////////////////////////////////////////////////////////////////////
// 动态规划 228ms
//int splitArray(vector<int>& nums, int m) {
//	int n = nums.size();
//	vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX));
//	vector<double> sub(n + 1, 0);
//	for (int i = 0; i < n; i++) {
//		sub[i + 1] = sub[i] + (double)nums[i];
//	}
//	f[0][0] = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			for (int k = 0; k < i; k++) {
//				f[i][j] = min(f[i][j], max(f[k][j - 1], (int)(sub[i] - sub[k])));
//			}
//		}
//	}
//	return f[n][m];
//}

//////////////////////////////////////////////////////////////////////////
// 二分查找 4ms
//bool canSplit(vector<int>& nums, int m, int split_sum) 
//{
//	long long sum = 0;
//	int cnt = 1;
//	for (auto &n : nums) 
//	{
//		sum += n;
//		if (sum <= split_sum) continue;
//
//		sum = n;
//		++cnt;
//		if (cnt > m) return false;
//	}
//	return true;
//}
//
//int splitArray(vector<int>& nums, int m) 
//{
//	long long l = 0;
//	long long r = 0;
//	for (auto &n : nums) 
//	{
//		r += n;
//		l = max(l, (long long)n);
//	}
//
//	while (l < r)
//	{
//		int mid = l + (r - l) / 2;
//		if (canSplit(nums, m, mid)) r = mid;
//		else l = mid + 1;
//	}
//	return r;
//}

//////////////////////////////////////////////////////////////////////////
// 4ms
int splitArray(vector<int>& nums, int m, int split_sum)
{
	long long sum = 0;
	long long nextsum = 0;
	int cnt = 1;
	for (int &n : nums) 
	{
		sum += n;
		if (sum <= split_sum) continue;

		nextsum = (nextsum == 0) ? sum : min(nextsum, sum);
		sum = n;
		++cnt;
		if (cnt > m) return splitArray(nums, m, nextsum);
	}
	return split_sum;
}

int splitArray(vector<int>& nums, int m)
{
	int num_max = 0;
	long long sum = 0;
	for (auto &n : nums)
	{
		num_max = max(num_max, n);
		sum += n;
	}
	return splitArray(nums, m, max((int)(sum / m), num_max));
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int m)
{
	return splitArray(nums,m);
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
	return "../../problems/split-array-largest-sum/tests.txt";
}

