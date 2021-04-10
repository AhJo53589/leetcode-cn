
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {
        int ans = INT_MAX;
        vector<vector<int>> vi(charge.size(), vector<int>(cnt + 1, INT_MAX));
        for (int i = 0; i <= cnt; i++) {
            vi[start][i] = i * charge[start];
        }

        vector<vector<int>> dis(charge.size(), vector<int>(charge.size(), -1));
        for (auto& p : paths) {
            dis[p[0]][p[1]] = p[2];
            dis[p[1]][p[0]] = p[2];
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({ 0, 0, start});

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

            for (int i = battery; i <= cnt; i++) {
                for (int j = 0; j < dis.size(); j++) {
                    if (dis[pos][j] == -1) continue;
                    if (dis[pos][j] > i) continue;
                    int tt = t + (i - battery) * charge[pos] + dis[pos][j];
                    if (vi[j][i] <= tt) continue;

                    vi[j][i] = tt;
                    pq.push({ tt, i - dis[pos][j], j });
                }
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
