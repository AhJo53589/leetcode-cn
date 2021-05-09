
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const int mod = 1e9 + 7;
        long long ans = 0;

        nums.insert(nums.begin(), 0);
        nums.push_back(0);

        vector<long long> ps(nums.size(), nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            ps[i] = ps[i - 1] + nums[i];
        }

        vector<int> st;
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.back()] > nums[i]) {
                int cur = nums[st.back()];
                st.pop_back();
                int left = st.back() + 1;
                int right = i - 1;
                ans = max(ans, (ps[right] - ps[left - 1]) * cur);
            }
            st.push_back(i);
        }

        return ans % mod;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxSumMinProduct(nums);
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
