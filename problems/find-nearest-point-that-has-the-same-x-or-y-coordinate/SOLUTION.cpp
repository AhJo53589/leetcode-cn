
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int dis = INT_MAX;
        for (int i = 0; i < points.size(); i++) {
            int dx = points[i][0];
            int dy = points[i][1];
            if (x != dx && y != dy) continue;
            int temp = abs(x - dx) + abs(y - dy);
            if (temp < dis) {
                dis = temp;
                ans = i;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int x, int y, vector<vector<int>>& points)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.nearestValidPoint(x, y, points);
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
