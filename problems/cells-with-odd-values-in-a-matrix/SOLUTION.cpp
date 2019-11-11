


//////////////////////////////////////////////////////////////////////////
int oddCells(int n, int m, vector<vector<int>>& indices)
{
    vector<vector<int>> matrix(n, vector<int>());
    for (auto &ma : matrix) ma.resize(m);

    for (auto in : indices)
    {
        for (auto x = 0; x < n; x++)
        {
            matrix[x][in[1]]++;
        }
        for (auto y = 0; y < m; y++)
        {
            matrix[in[0]][y]++;
        }
    }

    int ans = 0;
    for (auto a : matrix)
    {
        for (auto b : a)
        {
            ans += (b & 1);
        }
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, int m, vector<vector<int>>& indices)
{
	return oddCells(n,m,indices);
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
	return "../../problems/cells-with-odd-values-in-a-matrix/tests.txt";
}

