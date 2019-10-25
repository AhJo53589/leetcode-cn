//////////////////////////////////////////////////////////////////////////
int minimumMoves(vector<vector<int>>& grid) 
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
	return minimumMoves(grid);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//	vector<vector<int>>& grid(tc.get<vector<vector<int>>&>());
//	return minimumMoves(grid);
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/minimum-moves-to-reach-target-with-rotations/tests.txt";
}


