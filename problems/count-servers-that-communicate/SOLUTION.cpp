


//////////////////////////////////////////////////////////////////////////
int countServers(vector<vector<int>>& grid)
{
    vector<int> r(grid.size(), 0);
    vector<int> c(grid[0].size(), 0);
    int ans = 0;

    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                r[i]++;
                c[j]++;
            }
        }
    }
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                if (r[i] > 1 || c[j] > 1)
                {
                    ans++;
                }
            }
        }
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
	return countServers(grid);
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
	return "../../problems/count-servers-that-communicate/tests.txt";
}

