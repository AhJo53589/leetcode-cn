
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = lower_bound(nums, target);
        if (idx == nums.size() || nums[idx] != target) return 0;
        int idx2 = lower_bound(nums, target + 1);
        return idx2 - idx;
    }

    int lower_bound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
};
//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int target)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.search(nums, target);
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
