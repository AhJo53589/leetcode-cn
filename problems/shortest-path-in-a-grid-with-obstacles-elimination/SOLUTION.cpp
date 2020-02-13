


//////////////////////////////////////////////////////////////////////////
int shortestPath(vector<vector<int>>& grid, int k)
{
	vector<vector<int>> dd = { {0,1},{1,0},{0,-1},{-1,0} };
	int m = grid.size();
	int n = grid[0].size();

	vector<vector<vector<bool>>> vi(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
	queue<vector<int>> que;
	que.push({ 0,0,k,0 });
	vi[0][0][k] = true;

	while (!que.empty())
	{
		auto q = que.front();
		que.pop();
		if (q[0] == m - 1 && q[1] == n - 1) return q[3];

		for (auto d : dd)
		{
			int dx = q[0] + d[0];
			int dy = q[1] + d[1];
			if (dx < 0 || dx >= grid.size()) continue;
			if (dy < 0 || dy >= grid[0].size()) continue;

			int r = q[2] - grid[dx][dy];
			if (r < 0) continue;

			if (vi[dx][dy][r]) continue;
			vi[dx][dy][r] = true;

			que.push({ dx, dy, r, q[3] + 1 });
		}
	}
	return -1;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid, int k)
{
	return shortestPath(grid,k);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

