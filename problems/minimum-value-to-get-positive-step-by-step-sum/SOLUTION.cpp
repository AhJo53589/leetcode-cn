
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minStartValue(vector<int>& nums) 
    {
        vector<int> a;
        partial_sum(nums.begin(), nums.end(), back_inserter(a));
        int ans = *min_element(a.begin(), a.end());
        return ans <= 0 ? 1 - ans : 1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minStartValue(nums);
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
