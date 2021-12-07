
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int old = grid[row][col];
        if (old == color) return grid;
        dfs(grid, row, col, old);

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                grid[i][j] = (grid[i][j] == -2) ? color : grid[i][j];
                grid[i][j] = (grid[i][j] == -1) ? old : grid[i][j];
            }
        }
        return grid;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int old) {
        grid[row][col] = -2;
        int flag = 0;
        for (auto& d : dd) {
            int r = row + d[0];
            int c = col + d[1];
            if (r < 0 || r >= grid.size()) continue;
            if (c < 0 || c >= grid[0].size()) continue;
            flag += (grid[r][c] == old || grid[r][c] < 0);
            if (grid[r][c] != old) continue;
            dfs(grid, r, c, old);
        }
        grid[row][col] = (flag == 4) ? -1 : -2;
    }

private:
    vector<vector<int>> dd = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 } };
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& grid, int row, int col, int color)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.colorBorder(grid, row, col, color);
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
