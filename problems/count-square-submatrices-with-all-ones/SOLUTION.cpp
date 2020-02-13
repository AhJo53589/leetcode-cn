


//////////////////////////////////////////////////////////////////////////
int countSquares(vector<vector<int>>& matrix)
{
    int ans = 0;

    int len = 1;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] != len) continue;
                int dx = i + len;
                int dy = j + len;
                if (dx > matrix.size() || dy > matrix[i].size()) continue;

				bool ok = true;
				for (size_t ii = i; ii < dx && ok; ii++)
				{
					if (matrix[ii][dy - 1] == 0)
					{
						ok = false;
					}
				}
				for (size_t ii = j; ii < dy && ok; ii++)
				{
					if (matrix[dx - 1][ii] == 0)
					{
						ok = false;
					}
				}
				if (ok)
				{
					flag = true;
					matrix[i][j]++;
					ans++;
				}
			}
        }
        len++;
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& matrix)
{
	return countSquares(matrix);
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

