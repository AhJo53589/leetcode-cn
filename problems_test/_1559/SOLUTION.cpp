
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<char>> containsCycle(vector<vector<char>>& grid) {
        g = grid;
        vi = vector<vector<bool>>(g.size(), vector<bool>(g[0].size(), false));
        check = vector<vector<bool>>(g.size(), vector<bool>(g[0].size(), false));

        vector<vector<char>> ans;
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (vi[i][j]) continue;
                if (dfs_check(g[i][j], i, j, -1, -1)) {
                    int cnt = 0;
                    dfs_get(g[i][j], i, j, cnt);
                    vector<char> temp(cnt, g[i][j]);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }

    bool dfs_check(char c, int x, int y, int px, int py) {
        if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size()) return false;
        if (g[x][y] != c) return false;
        if (check[x][y]) return true;
        check[x][y] = true;
        for (auto d : dd) {
            int dx = x + d[0];
            int dy = y + d[1];
            if (dx == px && dy == py) continue;
            if (dfs_check(c, dx, dy, x, y)) return true;
        }
        return false;
    }

    void dfs_get(char c, int x, int y, int& cnt) {
        if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size()) return;
        if (g[x][y] != c) return;
        if (vi[x][y]) return;
        vi[x][y] = true;
        cnt++;
        for (auto d : dd) {
            int dx = x + d[0];
            int dy = y + d[1];
            dfs_get(c, dx, dy, cnt);
        }
    }

private:
    vector<vector<char>> g;
    vector<vector<bool>> vi;
    vector<vector<bool>> check;
    vector<vector<int>> dd = { {0,1}, {0,-1}, {1,0}, {-1,0} };
};

//////////////////////////////////////////////////////////////////////////
vector<vector<char>> _solution_run(vector<vector<char>>& grid)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorVectorT(grid);

    Solution sln;
    return sln.containsCycle(grid);
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
