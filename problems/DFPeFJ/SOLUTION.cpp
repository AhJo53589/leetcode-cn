
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {
        int ans = INT_MAX;
        vector<vector<int>> vi(charge.size(), vector<int>(cnt + 1, INT_MAX));
        vi[start][0] = 0;

        vector<vector<int>> dis(charge.size(), vector<int>(charge.size(), INT_MAX));
        for (auto& p : paths) {
            dis[p[0]][p[1]] = min(p[2], dis[p[0]][p[1]]);
            dis[p[1]][p[0]] = min(p[2], dis[p[1]][p[0]]);
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({ 0, 0, start });

        while (!pq.empty()) {
            auto q = pq.top();
            pq.pop();

            int t = q[0];
            int battery = q[1];
            int pos = q[2];

            if (pos == end) {
                ans = min(ans, t);
                continue;
            }
            if (t >= ans) continue;

            int chargeOne = battery + 1;
            int chargeTime = t + charge[pos];
            if (chargeOne <= cnt && chargeTime < vi[pos][chargeOne]) {
                pq.push({ chargeTime, chargeOne, pos });
            }

            for (int j = 0; j < dis.size(); j++) {
                if (dis[pos][j] == INT_MAX) continue;
                if (dis[pos][j] > battery) continue;
                int travelTime = t + dis[pos][j];
                int remain = battery - dis[pos][j];
                if (vi[j][remain] <= travelTime) continue;

                vi[j][remain] = travelTime;
                pq.push({ travelTime, remain, j });
            }
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.electricCarPlan(paths, cnt, start, end, charge);
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
