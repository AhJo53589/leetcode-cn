
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        dp = vector<vector<int>>(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        dp[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({ 0, 0, 0 });
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int x = p[1];
            int y = p[2];
            if (p[0] > dp[x][y]) continue;
            for (auto d : dd) {
                int dx = x + d[0];
                int dy = y + d[1];
                if (dx < 0 || dx >= heights.size()) continue;
                if (dy < 0 || dy >= heights[0].size()) continue;
                int diff = abs(heights[x][y] - heights[dx][dy]);
                diff = max(diff, dp[x][y]);
                if (dp[dx][dy] <= diff) continue;
                dp[dx][dy] = diff;
                pq.push({ diff, dx, dy });
            }
        }
        return dp.back().back();
    }

private:
    vector<vector<int>> dd = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    vector<vector<int>> dp;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& heights)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minimumEffortPath(heights);
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
