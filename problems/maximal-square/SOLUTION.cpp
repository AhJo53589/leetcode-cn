


//////////////////////////////////////////////////////////////////////////
int maximalSquare(vector<vector<char>>& matrix)
{
	if (matrix.empty()) return 0;
	int res = 0;
	vector<vector<int>> m(matrix.size(), vector<int>{});
	for (auto &_m : m) _m.resize(matrix[0].size());

	for (int i = 0; i < matrix.size(); i++)
	{
		m[i][0] = matrix[i][0] - '0';
		if (m[i][0] == 1) res = 1;
		if (matrix[0].size() == 1 && m[i][0] == 1) return res;
	}
	for (int j = 0; j < matrix[0].size(); j++)
	{
		m[0][j] = matrix[0][j] - '0';
		if (m[0][j] == 1) res = 1;
		if (matrix.size() == 1 && m[0][j] == 1) return res;
	}
	for (int i = 1; i < matrix.size(); i++)
	{
		for (int j = 1; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] == '1')
			{
				m[i][j] = min(min(m[i - 1][j], m[i][j - 1]), m[i - 1][j - 1]) + 1;
				res = max(res, m[i][j]);
			}
		}
	}
	return pow(res, 2);
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<char>>& matrix)
{
	return maximalSquare(matrix);
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

