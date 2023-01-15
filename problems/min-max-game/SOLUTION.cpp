
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        return calc(nums, true, nums.size(), 0);
    }

    int calc(vector<int>& nums, bool dir, int len, int idx) {
        if (len == 1) return nums[idx];

        int half = len / 2;
        int a = calc(nums, true, half, idx);
        int b = calc(nums, false, half, idx + half);
        return dir ? min(a, b) : max(a, b);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minMaxGame(nums);
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
