
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool dfs(vector<int>& nums, vector<bool>& vi, int idx, int sum)
    {
        if (sum == 0) return true;
        if (idx < 0) return false;

        for (int i = idx; i >= 0; i--)
        {
            if (vi[i]) continue;
            if (sum < nums[i]) continue;

            vi[i] = true;
            if (dfs(nums, vi, i - 1, sum - nums[i])) return true;
            vi[i] = false;
        }
        return false;
    }

    bool makesquare(vector<int>& nums) 
    {
        if (nums.size() < 4) return false;
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) return false;
        sum /= 4;
        
        vector<bool> vi(nums.size(), false);
        for (int i = 0; i < 4; i++)
        {
            if (!dfs(nums, vi, nums.size() - 1, sum)) return false;
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.makesquare(nums);
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
