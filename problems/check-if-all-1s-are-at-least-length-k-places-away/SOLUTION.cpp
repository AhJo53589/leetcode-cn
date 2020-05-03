
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int t = k;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1 && t < k) return false;
            t = (nums[i] == 0) ? t + 1 : 0;
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.kLengthApart(nums, k);
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
