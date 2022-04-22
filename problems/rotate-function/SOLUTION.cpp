
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int f = 0;
        for (int i = 0; i < nums.size(); i++) {
            f += i * nums[i];
        }

        int ans = f;
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            f += (sum - nums.size() * nums[i]);
            ans = max(ans, f);
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
	return sln.maxRotateFunction(nums);
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
