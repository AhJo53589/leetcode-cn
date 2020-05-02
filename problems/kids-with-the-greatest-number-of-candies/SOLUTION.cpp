
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size(), false);
        int mx = *max_element(candies.begin(), candies.end());
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = (candies[i] + extraCandies >= mx);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<bool> _solution_run(vector<int>& candies, int extraCandies)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.kidsWithCandies(candies, extraCandies);
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
