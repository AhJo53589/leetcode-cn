
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.rbegin(), nums.rend());

        int lo = 1;
        int hi = nums.front();
        while (lo < hi) {
            int md = lo + (hi - lo) / 2;
            if (!check(nums, maxOperations, md)) {
                lo = md + 1;
            }
            else {
                hi = md;
            }
        }
        return lo;
    }

    bool check(vector<int> nums, int maxOperations, int ans) {
        for (auto& n : nums) {
            int t = (n - 1) / ans;
            maxOperations -= t;
            if (maxOperations < 0) break;
        }
        return maxOperations >= 0;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int maxOperations)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    //printVectorT(nums);
    //cout << maxOperations << endl;

    Solution sln;
    return sln.minimumSize(nums, maxOperations);
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
