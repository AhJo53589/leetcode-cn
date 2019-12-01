


//////////////////////////////////////////////////////////////////////////
string tictactoe(vector<vector<int>>& moves) 
{
    int grid[3][3];
    memset(grid, 0, sizeof(grid));

	int ii = 0;
    for (auto m : moves)
    {
        grid[m[0]][m[1]] = ((ii++) & 1) ? -1 : 1;
    }

	vector<int> sum(8, 0);
    for (int i = 0; i < 3; i++)
    {
		sum[6] += grid[i][i];
		sum[7] += grid[2 - i][i];

        for (int j = 0; j < 3; j++)
        {
			sum[i * 2] += grid[i][j];
			sum[i * 2 + 1] += grid[j][i];
        }
    }

	for (auto s : sum)
	{
		if (s == 3) return "A";
		if (s == -3) return "B";
	}
    return moves.size() == 9 ? "Draw" : "Pending";
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<vector<int>>& moves)
{
	return tictactoe(moves);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
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
	return "../../problems/find-winner-on-a-tic-tac-toe-game/tests.txt";
}

