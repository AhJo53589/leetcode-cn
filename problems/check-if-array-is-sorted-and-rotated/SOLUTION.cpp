
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool check(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int pre = (i == 0) ? nums.back() : nums[i - 1];
            ans += (nums[i] < pre);
        }
        return ans < 2;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.check(nums);
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
