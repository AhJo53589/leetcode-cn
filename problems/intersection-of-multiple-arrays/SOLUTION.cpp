
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> cnt;
        for (auto& num : nums) {
            for (auto& n : num) {
                cnt[n]++;
            }
        }

        vector<int> ans;
        for (auto& p : cnt) {
            if (p.second != nums.size()) continue;
            ans.push_back(p.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.intersection(nums);
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
