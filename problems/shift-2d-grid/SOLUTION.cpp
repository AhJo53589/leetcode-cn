


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
{
    if (k-- == 0) return grid;

    vector<vector<int>> t(grid);
    for (int i = 0; i < t.size(); i++)
    {
        for (int j = 1; j < t[0].size(); j++)
        {
            grid[i][j] = t[i][j - 1];
        }
    }
    for (int i = 1; i < t.size(); i++)
    {
        grid[i][0] = t[i - 1][t[0].size() - 1];
    }
    grid[0][0] = t.back().back();

    return shiftGrid(grid, k);
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& grid, int k)
{
	return shiftGrid(grid,k);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

