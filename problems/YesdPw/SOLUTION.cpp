
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int largestArea(vector<string>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '0' || grid[i][j] == '-') continue;
                int cnt = 0;
                bool flag = true;
                dfs(grid, i, j, cnt, flag);
                if (!flag) continue;
                ans = max(ans, cnt);
            }
        }
        return ans;
    }

    bool check(vector<string>& grid, int i, int j) {
        if (i == 0 || i == grid.size() - 1) return false;
        if (j == 0 || j == grid[0].size() - 1) return false;
        for (auto d : dd) {
            int dx = i + d[0];
            int dy = j + d[1];
            if (grid[dx][dy] == '0') return false;
        }
        return true;
    }

    void dfs(vector<string>& grid, int i, int j, int& cnt, bool& flag) {
        flag &= check(grid, i, j);
        char val = grid[i][j];
        grid[i][j] = '-';
        cnt++;
        for (auto d : dd) {
            int dx = i + d[0];
            int dy = j + d[1];
            if (dx < 0 || dx == grid.size()) continue;
            if (dy < 0 || dy == grid[0].size()) continue;
            if (grid[dx][dy] != val) continue;
            dfs(grid, dx, dy, cnt, flag);
        }
    }

private:
    vector<vector<int>> dd = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& grid)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.largestArea(grid);
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
