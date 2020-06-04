

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int getNextNum(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& m) {
        int i = 0;
        int flag = 0;
        for (auto& d : dd) {
            int dx = x + d[0];
            int dy = y + d[1];
            if (dx < 0 || dx >= grid.size()) continue;
            if (dy < 0 || dy >= grid[0].size()) continue;
            if (grid[dx][dy] == 0) continue;

            i += 1;
            flag += d[0] + d[1];
        }
        //if (flag == 2) {    // 被证明是错的
            m.push_back({ x, y });
        //}
        return i;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& vi, int gain, int& ans) {
        gain += grid[x][y];
        ans = max(ans, gain);
        for (auto& d : dd) {
            int dx = x + d[0];
            int dy = y + d[1];
            if (dx < 0 || dx >= grid.size()) continue;
            if (dy < 0 || dy >= grid[0].size()) continue;
            if (grid[dx][dy] == 0) continue;
            if (vi[dx][dy] == 1) continue;
            vi[dx][dy] = 1;    // 回溯
            dfs(grid, dx, dy, vi, gain, ans);
            vi[dx][dy] = 0;
        }
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<int>> vi(grid.size(), vector<int>(grid[0].size(), 0));

        vector<vector<int>> m;
        int ans = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) continue;
                int nextNum = getNextNum(grid, i, j, m);
                if (nextNum == 0) {
                    ans = max(ans, grid[i][j]);
                    continue;
                }

                if (nextNum > 1) continue;
                // 处理突出结点
                vi[i][j] = 1;    // 永久
                dfs(grid, i, j, vi, 0, ans);
            }
        }
        if (!m.empty()) {
            for (auto& v : m) {
                int i = v[0];
                int j = v[1];
                vi[i][j] = 1;    // 回溯
                dfs(grid, i, j, vi, 0, ans);
                vi[i][j] = 0;    // 回溯
            }
        }
        return ans;
    }

private:
    vector<vector<int>> dd = { {0,1},{0,-1},{1,0},{-1,0} };
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorVectorT(grid);
    Solution sln;
    return sln.getMaximumGold(grid);
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
