
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        dp = vector<vector<int>>(nums.size(), vector<int>(nums.size(), 0));
        vi = vector<vector<bool>>(nums.size(), vector<bool>(nums.size(), false));
        int ans = dfs(nums, 0, nums.size() - 1);
        return ans >= 0;
    }

    int dfs(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        if (vi[left][right]) return dp[left][right];
        int n = max(nums[left] - dfs(nums, left + 1, right), nums[right] - dfs(nums, left, right - 1));
        dp[left][right] = n;
        return n;
    }

private:
    vector<vector<int>> dp;
    vector<vector<bool>> vi;
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.PredictTheWinner(nums);
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
