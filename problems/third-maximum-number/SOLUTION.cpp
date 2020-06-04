
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> ans;
        for (auto n : nums) {
            if (any_of(ans.begin(), ans.end(), [n](const int& a) { return a == n; })) {
                continue;
            }

            for (int i = 0; i < ans.size(); i++) {
                if (n > ans[i]) {
                    swap(n, ans[i]);
                }
            }

            if (ans.size() < 3) {
                ans.push_back(n);
            }
        }

        if (ans.empty()) return 0;
        if (ans.size() < 3) return ans.front();
        return ans.back();
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.thirdMax(nums);
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
