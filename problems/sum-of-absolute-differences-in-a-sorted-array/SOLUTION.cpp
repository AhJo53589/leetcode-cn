
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ps(1, 0);
        partial_sum(nums.begin(), nums.end(), back_inserter(ps));

        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = ps.back() + (i - (nums.size() - i)) * nums[i] - ps[i] * 2;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.getSumAbsoluteDifferences(nums);
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
