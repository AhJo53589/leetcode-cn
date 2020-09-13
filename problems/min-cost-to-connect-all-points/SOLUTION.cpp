
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 1) return 0;
        vi = vector<bool>(points.size(), false);
        dis = vector<vector<int>>(points.size(), vector<int>(points.size(), -1));
        int ans = 0;

        for (int i = 0; i < points.size(); i++) {
            if (vi[i]) continue;
            int d = INT_MAX;
            int v = -1;
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                int temp = calcDistance(points, i, j);
                if (temp < d) {
                    d = temp;
                    v = j;
                }
            }
            ans += d;
            vi[i] = true;
            vi[v] = true;
        }

        return ans;
    }

    int calcDistance(vector<vector<int>>& points, int p1, int p2) {
        if (p1 > p2) return calcDistance(points, p2, p1);
        if (dis[p1][p2] == -1) {
            dis[p1][p2] = abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
        }
        return dis[p1][p2];
    }

private:
    vector<bool> vi;
    vector<vector<int>> dis;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& points)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minCostConnectPoints(points);
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
