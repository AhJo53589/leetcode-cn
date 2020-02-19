
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxCoins(vector<int>& nums) 
	{
		cache = vector<vector<int>>(nums.size(), vector<int>(nums.size(), 0));
		int ans = getMaxCoins(nums, 0, nums.size() - 1);
		return ans;
    }

	int getMaxCoins(vector<int>& nums, int start, int end)
	{
		if (start > end) return 0;
		if (cache[start][end] != 0) return cache[start][end];

		for (int i = start; i <= end; i++)
		{
			int a = (start == 0) ? 1 : nums[start - 1];
			int b = (end == nums.size() - 1) ? 1 : nums[end + 1];
			int temp = a * nums[i] * b + getMaxCoins(nums, start, i - 1) + getMaxCoins(nums, i + 1, end);
			cache[start][end] = max(cache[start][end], temp);
		}
		return cache[start][end];
	}

private:
	vector<vector<int>> cache;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maxCoins(nums);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
