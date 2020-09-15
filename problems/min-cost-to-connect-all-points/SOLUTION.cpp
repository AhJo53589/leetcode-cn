
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> vi(points.size(), false);
        int n = points.size();
        int ans = 0;

        pq.push({ 0, 0 });
        while (!pq.empty() && n > 0) {
            auto[d, p1] = pq.top();
            pq.pop();
            if (vi[p1]) continue;

            ans += d;
            vi[p1] = true;
            n--;

            for (int p2 = 0; p2 < points.size(); p2++) {
                if (vi[p2]) continue;
                int dis = abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
                pq.push({ dis, p2 });
            }
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
