
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            swap(nums[0], nums[i]);
            if (dfs(0, nums)) break;
        }
        return nums;
    }

    bool dfs(int idx, vector<int>& nums) {
        if (idx == nums.size()) return true;

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            if (idx < 2 || nums[idx - 1] * 2 != nums[idx - 2] + nums[idx]) {
                if (dfs(idx + 1, nums)) return true;
            }
            swap(nums[i], nums[idx]);
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    printVectorT(nums);
    Solution sln;
    return sln.rearrangeArray(nums);
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
