
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        int bg = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) continue;
            ans = max(ans, getMaxLen(nums, bg, i));
            bg = i + 1;
        }
        ans = max(ans, getMaxLen(nums, bg, nums.size()));
        return ans;
    }

    int getMaxLen(vector<int>& nums, int bg, int ed) {
        int cnt = 0;
        int l = -1;
        int r = -1;
        for (int i = bg; i < ed; i++) {
            if (nums[i] > 0) continue;
            cnt++;
            l = (l == -1) ? i : l;
            r = i;
        }
        if (cnt % 2 == 0) return ed - bg;
        return max(ed - (l + 1), r - bg);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(nums);
    Solution sln;
    return sln.getMaxLen(nums);
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
