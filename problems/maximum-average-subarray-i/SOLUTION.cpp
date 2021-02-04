
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        double sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                sum -= nums[i - k];
            }
            sum += nums[i];
            if (i >= k - 1) {
                ans = max(ans, sum / k);
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
double _solution_run(vector<int>& nums, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findMaxAverage(nums, k);
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
