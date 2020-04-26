
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int su = 0;
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            su += cardPoints[i];
        }
        ans = max(ans, su);
        for (int i = 0; i < k; ++i) {
            su -= cardPoints[k - i - 1];
            su += cardPoints[cardPoints.size() - i - 1];
            ans = max(ans, su);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& cardPoints, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxScore(cardPoints, k);
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
