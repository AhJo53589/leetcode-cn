
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        g = grid;
        vi = vector<vector<bool>>(g.size(), vector<bool>(g[0].size(), false));

        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (g[i][j] == '.') continue;
                if (dfs(g[i][j], i, j, -1, -1)) return true;
            }
        }
        return false;
    }

    bool dfs(char c, int x, int y, int px, int py) {
        if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size()) return false;
        if (g[x][y] != c) return false;
        if (vi[x][y]) return true;
        vi[x][y] = true;
        for (auto d : dd) {
            int dx = x + d[0];
            int dy = y + d[1];
            if (dx == px && dy == py) continue;
            if (dfs(c, dx, dy, x, y)) return true;
        }
        vi[x][y] = false;
        g[x][y] = '.';
        return false;
    }

private:
    vector<vector<char>> g;
    vector<vector<bool>> vi;
    vector<vector<int>> dd = { {0,1}, {0,-1}, {1,0}, {-1,0} };
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<vector<char>>& grid)
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
