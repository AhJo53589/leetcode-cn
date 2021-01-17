
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int ans = 0;
        int maxLen = -1;
        for (auto& r : rectangles) {
            int len = min(r[0], r[1]);
            ans = (len > maxLen) ? 1 : (len == maxLen) ? ans + 1 : ans;
            maxLen = max(len, maxLen);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& rectangles)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.countGoodRectangles(rectangles);
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
