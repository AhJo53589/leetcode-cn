
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) 
    {
        sort(nums.rbegin(), nums.rend());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans;
        int cur = 0;
        for (auto n : nums)
        {
            ans.push_back(n);
            cur += n;
            if (cur * 2 > sum) break;
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
    return sln.minSubsequence(nums);
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
