
void checkIsland(vector<vector<char>>& grid, pair<int, int> posStart)
{
	queue<pair<int, int>> q;
	q.push(posStart);

	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();

		if (p.first >= 0 && p.first < grid.size() && p.second >= 0 && p.second < grid[0].size())
		{
			if (grid[p.first][p.second] == '1')
			{
				grid[p.first][p.second] = '2';

				q.push(make_pair(p.first, p.second - 1));
				q.push(make_pair(p.first, p.second + 1));
				q.push(make_pair(p.first - 1, p.second));
				q.push(make_pair(p.first + 1, p.second));
			}
		}
	}
}


//////////////////////////////////////////////////////////////////////////
int numIslands(vector<vector<char>>& grid)
{
	int iLen_i = grid.size();
	if (iLen_i == 0) return 0;
	int iLen_j = grid[0].size();
	if (iLen_j == 0) return 0;

	int num = 0;
	for (int i = 0; i < iLen_i; i++)
	{
		for (int j = 0; j < iLen_j; j++)
		{
			if (grid[i][j] == '1')
			{
				checkIsland(grid, make_pair(i, j));
				num++;
			}
		}
	}

	return num;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<char>>& grid)
{
	return numIslands(grid);
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

