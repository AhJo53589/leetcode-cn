
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int lowerbound(vector<int>& nums, int target, int low, int high)
    {
        while (low < high)
        {
            while (low != high - 1 && nums[low] == nums[high - 1])
            {
                high--;
            }
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else if (nums[mid] <= nums[high - 1])
            {
                if (nums[mid] <= target && target <= nums[high - 1])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid;
                }
            }
        }
        return low;
    }

    bool search(vector<int>& nums, int target)
    {
        int ans = lowerbound(nums, target, 0, nums.size());
        return !(ans == nums.size() || nums[ans] != target);
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums, int target)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(nums, 3);
    Solution sln;
    return sln.search(nums, target);
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
