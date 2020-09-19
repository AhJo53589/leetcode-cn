
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> cnt(nums.size() + 1, 0);
        for (int i = 0; i < requests.size(); i++) {
            cnt[requests[i][0]]++;
            cnt[requests[i][1] + 1]--;
        }
        for (int i = 1; i < cnt.size(); i++) {
            cnt[i] += cnt[i - 1];
        }

        sort(nums.rbegin(), nums.rend());
        sort(cnt.rbegin(), cnt.rend());
        const int mod = 1e9 + 7;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += (nums[i] * cnt[i]) % mod;
            ans %= mod;
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, vector<vector<int>>& requests)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    //printVectorT(nums);
    //printVectorVectorT(requests);
    Solution sln;
    return sln.maxSumRangeQuery(nums, requests);
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
