
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() < 5) return 0;

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;
        for (int i = 0; i <= 3; i++) {
            ans = min(ans, nums[nums.size() - 1 - (3 - i)] - nums[i]);
        }
        return ans;
    }
};

class Solution2 {
public:
    int minDifference(vector<int>& nums) {
        multiset<int> cnt;
        for (auto& n : nums) {
            cnt.insert(n);
        }

        int ans = INT_MAX;
        for (int i = 0; i <= 3; i++) {
            auto temp = cnt;

            for (int j = 0; j < i && !temp.empty(); j++) {
                temp.erase(temp.begin());
            }
            for (int j = 0; j < 3 - i && !temp.empty(); j++) {
                temp.erase(temp.find(*temp.rbegin()));
            }

            if (temp.size() < 2) {
                ans = 0;
                break;
            }
            ans = min(ans, *temp.rbegin() - *temp.begin());
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(nums);
    Solution sln;
    return sln.minDifference(nums);
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
