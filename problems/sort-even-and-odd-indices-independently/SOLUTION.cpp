
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<vector<int>> st(2, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            st[i % 2].push_back(nums[i]);
        }
        sort(st[0].begin(), st[0].end());
        sort(st[1].rbegin(), st[1].rend());
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < st[0].size(); i++) {
            ans[i * 2] = st[0][i];
        }
        for (int i = 0; i < st[1].size(); i++) {
            ans[i * 2 + 1] = st[1][i];
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
    return sln.sortEvenOdd(nums);
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
