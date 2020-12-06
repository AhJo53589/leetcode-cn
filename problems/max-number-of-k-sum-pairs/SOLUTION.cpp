
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int ans = 0;
        for (auto n : nums) {
            if (um[k - n] != 0) {
                ans++;
                um[k - n]--;
                continue;
            }
            um[n]++;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxOperations(nums, k);
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
