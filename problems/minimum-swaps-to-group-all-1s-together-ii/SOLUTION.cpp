
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt = accumulate(nums.begin(), nums.end(), 0);
        if (cnt == nums.size() || cnt == 0 || cnt == 1) return 0;

        int j = 0;
        int window = 0;
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            while (true) {
                int x = (i > j) ? nums.size() + j : j;
                if (x >= i + cnt) break;
                window += nums[j];
                j = (j + 1 == nums.size()) ? 0 : j + 1;
            }
            ans = min(ans, cnt - window);
            window -= nums[i];
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
    return sln.minSwaps(nums);
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
