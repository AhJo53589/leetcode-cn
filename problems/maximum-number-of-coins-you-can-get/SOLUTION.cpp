
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        sort(piles.rbegin(), piles.rend());
        int t = piles.size() / 3;
        for (int i = 0; i < piles.size() && t > 0; i++) {
            if (i % 2 != 1) continue;
            ans += piles[i];
            t--;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& piles)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxCoins(piles);
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
