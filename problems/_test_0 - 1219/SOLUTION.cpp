


//////////////////////////////////////////////////////////////////////////
int dfs(vector<vector<int>>& grid, int x, int y)
{
	if (x < 0 || x >= grid.size()) return 0;
	if (y < 0 || y >= grid[0].size()) return 0;
	if (grid[x][y] <= 0) return 0;
	grid[x][y] *= -1;

	int ans = 0;
	vector<vector<int>> dd = { {0,1},{1,0},{0,-1},{-1,0} };
	for (auto &d : dd)
	{
		int dx = x + d[0];
		int dy = y + d[1];
		ans = max(ans, dfs(grid, dx, dy));
	}

	grid[x][y] *= -1;
	return ans + grid[x][y];
}

int getMaximumGold(vector<vector<int>>& grid) 
{
	int ans = 0;
	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t j = 0; j < grid[0].size(); j++)
		{
			ans = max(ans, dfs(grid, i, j));
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
	return getMaximumGold(grid);
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
	return "../../problems/_test_0/tests.txt";
}

