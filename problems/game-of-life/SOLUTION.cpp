


//////////////////////////////////////////////////////////////////////////
void gameOfLife(vector<vector<int>>& board)
{
	size_t m = board.size();
	if (m == 0) return;
	size_t n = board[0].size();

	auto getNear = [m, n](size_t _i, size_t _j, vector<vector<size_t>> &pos)
	{
		for (size_t i = max((size_t)1, _i) - 1; i < min(m, _i + 2); i++)
		{
			for (size_t j = max((size_t)1, _j) - 1; j < min(n, _j + 2); j++)
			{
				if (i == _i && j == _j) continue;
				pos.push_back({ i, j });
			}
		}
	};

	for (size_t i = 0; i < board.size(); i++)
	{
		for (size_t j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] > 0)
			{
				vector<vector<size_t>> pos;
				getNear(i, j, pos);
				for (auto &p : pos)
				{
					int &x = board[p[0]][p[1]];
					x = (x > 0) ? x + 1 : x - 1;
				}
			}
		}
	}

	for (size_t i = 0; i < board.size(); i++)
	{
		for (size_t j = 0; j < board[i].size(); j++)
		{
			int &x = board[i][j];
			if (x > 0)
			{
				x = (x == 2 + 1 || x == 3 + 1) ? 1 : 0;
			}
			else
			{
				x = (x == -3) ? 1 : 0;
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& board)
{
	gameOfLife(board);
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

