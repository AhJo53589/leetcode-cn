
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> cnt;
        for (auto n : nums) {
            cnt[n]++;
        }

        int ans = 0;
        int curCount = 0;
        for (auto it = cnt.rbegin(); it != cnt.rend(); it++) {
            curCount += it->second;
            ans += curCount;
        }
        return ans - curCount;
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
    return sln.reductionOperations(nums);
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
