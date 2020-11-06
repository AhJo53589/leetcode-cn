
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans = 0;
        sort(points.begin(), points.end());
        for (int i = 1; i < points.size(); i++) {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& points)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxWidthOfVerticalArea(points);
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
