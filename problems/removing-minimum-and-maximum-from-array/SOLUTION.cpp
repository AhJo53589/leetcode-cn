
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        if (nums.size() == 3) return 2;

        int lo = 0;
        int hi = 0;
        for (int i = 0; i < nums.size(); i++) {
            lo = (nums[i] < nums[lo]) ? i : lo;
            hi = (nums[i] > nums[hi]) ? i : hi;
        }
        vector<int> ans;
        ans.push_back(max(lo, hi) + 1);
        ans.push_back(nums.size() - min(lo, hi));
        ans.push_back(min(lo, hi) + nums.size() - max(lo, hi) + 1);
        return *min_element(ans.begin(), ans.end());
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minimumDeletions(nums);
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
