
//////////////////////////////////////////////////////////////////////////
void dfs(vector<vector<int>> &grid, size_t x, size_t y, int &ans)
{
	if (x >= grid.size() || y >= grid[0].size()) return;
	if (grid[x][y] != 1) return;

	grid[x][y] = 2;

	const int dx[4] = { 1,-1,0,0 };
	const int dy[4] = { 0,0,1,-1 };
	for (int i = 0; i < 4; i++)
	{
		size_t tx = x + dx[i];
		size_t ty = y + dy[i];

		ans += (tx >= grid.size());
		ans += (ty >= grid[0].size());
		if (tx >= grid.size() || ty >= grid[0].size()) continue;
		ans += (grid[tx][ty] == 0);

		dfs(grid, tx, ty, ans);
	}
}

int islandPerimeter(vector<vector<int>>& grid) 
{
	int ans = 0;
	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j] == 1)
			{
				dfs(grid, i, j, ans);
				return ans;
			}
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
	return islandPerimeter(grid);
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
	return "../../problems/island-perimeter/tests.txt";
}

