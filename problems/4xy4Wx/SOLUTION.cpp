
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        const long long mod = 1e9 + 7;
        long long ans = 0;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) break;

            auto it = upper_bound(nums.begin() + i + 1, nums.end(), target - nums[i]);
            ans += (it - nums.begin()) - i - 1;
            ans %= mod;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int target)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(nums);
    cout << target << endl;

    Solution sln;
    return sln.purchasePlans(nums, target);
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
