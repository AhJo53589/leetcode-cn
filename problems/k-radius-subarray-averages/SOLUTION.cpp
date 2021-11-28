
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<long long> lnums(nums.begin(), nums.end());
        vector<long long> ps(1, 0);
        partial_sum(lnums.begin(), lnums.end(), back_inserter(ps));

        vector<int> ans(nums.size(), -1);
        for (int i = k; i < (int)nums.size() - k; i++) {
            int avg = (ps[i + k + 1] - ps[i - k]) / (2 * k + 1);
            ans[i] = avg;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.getAverages(nums, k);
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
