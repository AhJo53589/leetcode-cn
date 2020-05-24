
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, INT_MIN));

        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] * nums2[j - 1] > 0) {
                    dp[i][j] = max(0, dp[i - 1][j - 1]) + nums1[i - 1] * nums2[j - 1];
                    dp[i][j] = max({ dp[i][j], dp[i - 1][j], dp[i][j - 1] });
                }
                else {
                    dp[i][j] = max(nums1[i - 1] * nums2[j - 1], max(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }

        return dp.back().back();
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums1, vector<int>& nums2)
{
    //int caseNo = 3;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(nums1);
    printVectorT(nums2);
    Solution sln;
    return sln.maxDotProduct(nums1, nums2);
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
