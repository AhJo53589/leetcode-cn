
//////////////////////////////////////////////////////////////////////////
void dfs(vector<vector<int>>& g, size_t x, size_t y, int &val)
{
    if (x >= g.size() || y >= g[0].size())
    {
        val = 0;
        return;
    }

    if (g[x][y] != 0) return;
    g[x][y] = -1;

    dfs(g, x + 1, y, val);
    dfs(g, x - 1, y, val);
    dfs(g, x, y + 1, val);
    dfs(g, x, y - 1, val);       
}

int closedIsland(vector<vector<int>>& grid)
{
    int ans = 0;
    for (size_t x = 0; x < grid.size(); x++)
    {
        for (size_t y = 0; y < grid[0].size(); y++)
        {
            if (grid[x][y] == 0)
            {
                int val = 1;
                dfs(grid, x, y, val);
                ans += val;
            }
        }
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
	return closedIsland(grid);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/number-of-closed-islands/tests.txt";
}

