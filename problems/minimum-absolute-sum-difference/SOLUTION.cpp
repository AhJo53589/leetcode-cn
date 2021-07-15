
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int mod = 1e9 +7;
        vector<int> s(nums1);
        sort(s.begin(), s.end());

        int ans = 0;
        int maxDiff = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int diff = abs(nums1[i] - nums2[i]);
            ans += diff;
            ans %= mod;

            int j = lower_bound(s.begin(), s.end(), nums2[i]) - s.begin();
            maxDiff = (j < nums1.size()) ? max(maxDiff, diff - (s[j] - nums2[i])) : maxDiff;
            maxDiff = (j > 0) ? max(maxDiff, diff - (nums2[i] - s[j - 1])) : maxDiff;
        }

        return (ans - maxDiff + mod) % mod;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums1, vector<int>& nums2)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minAbsoluteSumDiff(nums1, nums2);
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
