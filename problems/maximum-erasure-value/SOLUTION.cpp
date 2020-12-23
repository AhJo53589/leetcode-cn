
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> vi;
        vector<int> sums = { 0 };
        partial_sum(nums.begin(), nums.end(), back_inserter(sums));

        int ans = 0;
        int sum = 0;
        int prev = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (vi.find(nums[i]) != vi.end()) {
                prev = max(prev, vi[nums[i]] + 1);
            }

            vi[nums[i]] = i;
            sum = sums[i + 1] - sums[prev];
            ans = max(ans, sum);
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
    return sln.maximumUniqueSubarray(nums);
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
