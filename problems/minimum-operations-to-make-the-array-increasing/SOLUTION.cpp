
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int prev = 0;
        for (auto n : nums) {
            ans += max(prev + 1 - n, 0);
            prev = max(prev + 1, n);
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
    return sln.minOperations(nums);
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
