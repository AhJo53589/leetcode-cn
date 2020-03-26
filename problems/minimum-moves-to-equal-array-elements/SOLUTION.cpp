
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int ans = 0;
        int n = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (n > nums[i])
            {
                ans += (i * (n - nums[i]));
                n = nums[i];
            }
            else
            {
                ans += (nums[i] - n);
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minMoves(nums);
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
