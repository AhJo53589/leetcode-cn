
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n < 2) return n;
        int ans = 1;
        vector<int> nums(n + 1, 0);
        nums[0] = 0;
        nums[1] = 1;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = (i % 2 == 0) ? nums[i / 2] : nums[i / 2] + nums[i / 2 + 1];
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.getMaximumGenerated(n);
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
