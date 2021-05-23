
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        vector<int> ps = { 0 };
        partial_sum(stones.begin(), stones.end(), back_inserter(ps));
        
        vector<int> dp = vector<int>(stones.size(), 0);
        int mx = ps.back();
        for (int i = (int)stones.size() - 1; ~i; i--) {
            dp[i] = mx;
            mx = max(mx, ps[i] - dp[i]);
        }
        return dp[1];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& stones)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(stones);

    Solution sln;
    return sln.stoneGameVIII(stones);
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
