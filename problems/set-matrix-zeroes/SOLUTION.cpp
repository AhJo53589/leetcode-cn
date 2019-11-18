


//////////////////////////////////////////////////////////////////////////
void setZeroes(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	if (m == 0) return;
	int n = matrix[0].size();

	bool bZeroH = (matrix[0][0] == 0);
	bool bZeroV = (matrix[0][0] == 0);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				if (i == 0) bZeroH = true;
				else matrix[i][0] = 0;
				if (j == 0) bZeroV = true;
				else matrix[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < m; i++)
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 1; j < n; j++) matrix[i][j] = 0;
		}
	}

	for (int j = 1; j < n; j++)
	{
		if (matrix[0][j] == 0)
		{
			for (int i = 1; i < m; i++) matrix[i][j] = 0;
		}
	}
	if (bZeroH)
	{
		for (int j = 0; j < n; j++) matrix[0][j] = 0;
	}
	if (bZeroV)
	{
		for (int i = 0; i < m; i++) matrix[i][0] = 0;
	}
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& matrix)
{
	setZeroes(matrix);
	return matrix;
}

//#define USE_SOLUTION_CUSTOM
//void _solution_custom(TestCases &tc)
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
	return "../../problems/set-matrix-zeroes/tests.txt";
}

