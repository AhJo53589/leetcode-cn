
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int x = 0; x < (1 << n); x++) {
            int s = 0;
            for (int i = 0; i < nums.size(); i++) {
                if ((x & (1 << i)) == 0) continue;
                s ^= nums[i];
            }
            ans += s;
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
    printVectorT(nums);
    Solution sln;
    return sln.subsetXORSum(nums);
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
