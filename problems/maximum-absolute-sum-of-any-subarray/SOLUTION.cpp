
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        return max(maxSubArray(nums, 1), maxSubArray(nums, -1));
    }

    int maxSubArray(vector<int>& nums, int p) {
        if (nums.empty()) return 0;
        int dp = p * nums[0];
        int ans = dp;
        for (int i = 1; i < nums.size(); i++) {
            int n = p * nums[i];
            dp = max(dp + n, n);
            ans = max(ans, dp);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    printVectorT(nums);

    Solution sln;
    return sln.maxAbsoluteSum(nums);
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
