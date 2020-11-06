
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto n : nums) {
            cnt[n]++;
        }
        sort(nums.begin(), nums.end(), [&cnt](int a, int b) {
            return (cnt[a] == cnt[b]) ? a > b : cnt[a] < cnt[b];
        });
        return nums;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.frequencySort(nums);
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
