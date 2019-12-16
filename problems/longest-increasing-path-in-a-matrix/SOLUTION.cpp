
//////////////////////////////////////////////////////////////////////////
void calc(vector<vector<int>>& m, int x, int y, vector<vector<int>>& c, vector<vector<int>>& dd)
{
    if (x < 0 || x >= m.size() || y < 0 || y >= m[0].size()) return;

    int cnt = -1;
    for (auto i = 0; i < dd.size(); i++)
    {
        int dx = x + dd[i][0];
        int dy = y + dd[i][1];
        if (dx < 0 || dx >= m.size() || dy < 0 || dy >= m[0].size())
        {
            continue;
        }
        if (m[dx][dy] < m[x][y])
        {
            if (c[dx][dy] == -1) return;
            cnt = max(cnt, c[dx][dy]);
        }
    }
    c[x][y] = cnt + 1;
}

int longestIncreasingPath(vector<vector<int>>& matrix) 
{
    if (matrix.size() == 0) return 0;
    vector<vector<int>> dd = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> c(matrix.size(), vector<int>(matrix[0].size(), -1));

    int ans = 0;
    bool flag = false;
    while (!flag)
    {
        flag = true;
        for (int x = 0; x < matrix.size(); x++)
        {
            for (int y = 0; y < matrix[0].size(); y++)
            {
                if (c[x][y] < 0)
                {
                    calc(matrix, x, y, c, dd);
                }
                if (c[x][y] < 0)
                {
                    flag = false;
                }
                ans = max(ans, c[x][y]);
            }
        }
    }
    return ans + 1;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& matrix)
{
    printVectorVectorT(matrix);
	return longestIncreasingPath(matrix);
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
	return "../../problems/longest-increasing-path-in-a-matrix/tests.txt";
}

