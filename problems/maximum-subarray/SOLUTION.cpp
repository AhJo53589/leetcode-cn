
//int maxSubArray(vector<int>& nums)
//{
//	//法1：复杂度为O(n)的解法
//	int res = INT_MIN, sum = 0;
//	for (int n : nums) {
//		sum = max(n, sum + n);
//		res = max(sum, res);
//	}
//	return res;
//}

//////////////////////////////////////////////////////////////////////////
int maxSubArrayCross(vector<int> &nums, int low, int mid, int high)
{
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int sum = 0;
	for (int i = mid; i >= 0; i--)
	{
		sum += nums[i];
		left_sum = max(left_sum, sum);
	}
	sum = 0;
	for (int i = mid + 1; i <= high; i++)
	{
		sum += nums[i];
		right_sum = max(right_sum, sum);
	}
	return left_sum + right_sum;
}

int maxSubArraySide(vector<int>& nums, int low, int high)
{
	if (low == high) return nums[low];

	int _Mid = low + (high - low) / 2;
	int left_sum = maxSubArraySide(nums, low, _Mid);
	int right_sum = maxSubArraySide(nums, _Mid + 1, high);
	int cross_sum = maxSubArrayCross(nums, low, _Mid, high);

	return max(left_sum, max(right_sum, cross_sum));
}

int maxSubArray(vector<int>& nums)
{
	int low = 0;
	int high = nums.size() - 1;
	return maxSubArraySide(nums, low, high);
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return maxSubArray(nums);
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

