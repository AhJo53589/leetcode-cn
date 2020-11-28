
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(nums.size(), 0));
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[0][i] = max(dp[0][i], dp[0][j] + 1);

                }
            }
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            for (int j = nums.size() - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    dp[1][i] = max(dp[1][i], dp[1][j] + 1);
                }
            }
        }

        int t = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            t = max(t, dp[0][i] + dp[1][i] + 1);
        }
        return nums.size() - t;
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
    return sln.minimumMountainRemovals(nums);
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
