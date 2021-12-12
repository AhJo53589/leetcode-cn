
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long _min = nums[i];
            long long _max = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                _min = min(1LL * nums[j], _min);
                _max = max(1LL * nums[j], _max);
                ans += (_max - _min);
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
long _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.subArrayRanges(nums);
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
