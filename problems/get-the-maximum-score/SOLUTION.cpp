
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        nums1.push_back(mod);
        nums2.push_back(mod);
        int ans = 0;
        int idx1 = 0;
        int idx2 = 0;
        int sum1 = 0;
        int sum2 = 0;
        int m1 = 0;
        int m2 = 0;

        while (idx1 < nums1.size() && idx2 < nums2.size()) {
            int n1 = nums1[idx1];
            int n2 = nums2[idx2];
            sum1 += (n1 <= n2) ? n1 : 0;
            sum2 += (n1 >= n2) ? n2 : 0;

            m1 += (sum1 >= mod);
            sum1 -= (sum1 >= mod) ? mod : 0;
            m2 += (sum2 >= mod);
            sum2 -= (sum2 >= mod) ? mod : 0;

            if (n1 == n2){
                if (m1 != m2) {
                    ans += (m1 > m2) ? sum1 : sum2;
                }
                else {
                    ans += max(sum1, sum2);
                }
                ans %= mod;
                sum1 = 0;
                sum2 = 0;
                m1 = 0;
                m2 = 0;
            }

            idx1 += (n1 <= n2);
            idx2 += (n1 >= n2);
        }
        return ans;
    }

private:
    const int mod = 1e9 + 7;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums1, vector<int>& nums2)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxSum(nums1, nums2);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
