
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans.insert(ans.begin() + index[i], nums[i]);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums, vector<int>& index)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.createTargetArray(nums, index);
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
