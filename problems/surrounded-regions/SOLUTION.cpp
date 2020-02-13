
//////////////////////////////////////////////////////////////////////////
void dfs(vector<vector<char>>& board, size_t x, size_t y)
{
	if (x >= board.size() || y >= board[x].size() || board[x][y] != 'O') return;
	board[x][y] = '-';
	dfs(board, x - 1, y);
	dfs(board, x + 1, y);
	dfs(board, x, y - 1);
	dfs(board, x, y + 1);
}

//////////////////////////////////////////////////////////////////////////
void solve(vector<vector<char>>& board)
{
	size_t m = board.size();
	if (m == 0) return;
	size_t n = board[0].size();

	for (size_t i = 0; i < m; i++)
	{
		dfs(board, i, 0);
		dfs(board, i, n - 1);
	}
	for (size_t j = 0; j < n; j++)
	{
		dfs(board, 0, j);
		dfs(board, m - 1, j);
	}

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			board[i][j] = (board[i][j] != '-') ? 'X' : 'O';
		}
	}
}

//////////////////////////////////////////////////////////////////////////
vector<vector<char>> _solution_run(vector<vector<char>>& board)
{
	solve(board);
	return board;
}

//#define USE_SOLUTION_CUSTOM
//void _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

