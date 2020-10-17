
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<vector<int>> quality(51, vector<int>(51, 0));
        vector<int> ans(3, 0);

        for (int i = 0; i <= 50; i++) {
            for (int j = 0; j <= 50; j++) {
                for (auto t : towers) {
                    double dis = getDis(i, j, t[0], t[1]);
                    if (radius < dis) continue;
                    quality[i][j] += (int)((double)t[2] / (double)(1 + dis));
                }
                int temp = quality[i][j];
                if (ans[2] < temp) {
                    ans = { i, j, temp };
                }
            }
        }

        return { ans[0], ans[1] };
    }

    double getDis(int i, int j, int x, int y) {
        double ans = sqrt((i - x) * (i - x) + (j - y) * (j - y));
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& towers, int radius)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.bestCoordinate(towers, radius);
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
