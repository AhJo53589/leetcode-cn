
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int res = pow(2, maximumBit) - 1;
        for (auto n : nums) {
            res ^= n;
        }

        vector<int> ans(nums.size());
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = res;
            res ^= nums[(int)nums.size() - 1 - i];
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums, int maximumBit)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.getMaximumXor(nums, maximumBit);
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
