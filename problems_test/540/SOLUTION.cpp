
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() / 2;
        while (lo < hi) {
            int mid = lo + (hi - lo ) / 2;
            if (nums[mid * 2] == nums[mid * 2 + 1]) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        return nums[lo * 2];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.singleNonDuplicate(nums);
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
