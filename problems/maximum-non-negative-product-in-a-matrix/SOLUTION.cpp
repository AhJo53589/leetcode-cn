
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        bool zero = false;
        vector<vector<bool>> vi(grid.size(), vector<bool>(grid[0].size(), false));
        vector<vector<vector<bool>>> use(2, vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false)));
        use[0][0][0] = grid[0][0] >= 0;
        use[1][0][0] = grid[0][0] <= 0;
        vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(grid.size(), vector<long long>(grid[0].size(), 0)));
        dp[0][0][0] = grid[0][0] > 0 ? grid[0][0] : 0;
        dp[1][0][0] = grid[0][0] < 0 ? grid[0][0] : 0;

        queue<pair<int, int>> que;
        que.push({ 0, 0 });
        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            if (grid[x][y] == 0) {
                zero = true;
            }

            for (auto d : dd) {
                int dx = x + d[0];
                int dy = y + d[1];
                if (dx < grid.size() && dy < grid[0].size()) {
                    for (int i = 0; i < 2; i++) {
                        if (!use[i][x][y]) continue;
                        long long p = dp[i][x][y] * grid[dx][dy];
                        if (p >= 0) {
                            dp[0][dx][dy] = max(dp[0][dx][dy], p);
                            use[0][dx][dy] = true;
                        }
                        else if (p <= 0) {
                            dp[1][dx][dy] = min(dp[1][dx][dy], p);
                            use[1][dx][dy] = true;
                        }
                    }
                    if (!vi[dx][dy]) {
                        que.push({ dx, dy });
                        vi[dx][dy] = true;
                    }
                }
            }
        }

        if (use[0].back().back()) return (int)(dp[0].back().back() % mod);
        return zero ? 0 : -1;
    }

private:
    const long long mod = 1e9 + 7;
    vector<vector<int>> dd{ {0, 1}, {1, 0} };
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorVectorT(grid);
    Solution sln;
    return sln.maxProductPath(grid);
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
