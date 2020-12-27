
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = dfs(grid, 0, i);
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x == grid.size()) return y;

        int dy = (grid[x][y] == 1) ? y + 1 : y - 1;
        if (dy >= 0 && dy < grid[x].size() && grid[x][dy] == grid[x][y]) {
            return dfs(grid, x + 1, dy);
        }
        return -1;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& grid)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.findBall(grid);
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
