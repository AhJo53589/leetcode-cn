
//////////////////////////////////////////////////////////////////////////
void dfs(vector<vector<int>> &grid, int i, int j, int &ans)
{
	int m = grid.size();
	if (m == 0) return;
	int n = grid[0].size();
	if (n == 0) return;
	if (i >= m || i < 0) return;
	if (j >= n || j < 0) return;
	if (grid[i][j] == 0) return;

	ans++;
	grid[i][j] = 0;
	dfs(grid, i - 1, j, ans);
	dfs(grid, i + 1, j, ans);
	dfs(grid, i, j - 1, ans);
	dfs(grid, i, j + 1, ans);
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
	int ans = 0;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			int temp = 0;
			dfs(grid, i, j, temp);
			ans = max(ans, temp);
		}
	}
	return ans;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
	return maxAreaOfIsland(grid);
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
	return "../../problems/max-area-of-island/tests.txt";
}

