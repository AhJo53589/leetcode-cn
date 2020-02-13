
//vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
//{
//	if (matrix.empty()) return vector<int>();
//	int rows = matrix.size();
//	int cols = matrix[0].size();
//	vector<int> output;
//	int i = 0, j = 0;
//	output.push_back(matrix[i][j]);
//	while (i != rows - 1 || j != cols - 1)
//	{
//		if (j + 1 < cols) j++;
//		else if (i + 1 < rows) i++;
//		output.push_back(matrix[i][j]);
//
//		while (i + 1 < rows && j - 1 >= 0)
//		{
//			i++;
//			j--;
//			output.push_back(matrix[i][j]);
//		}
//
//		if (i + 1 < rows) i++;
//		else if (j + 1 < cols) j++;
//		else return output;
//		output.push_back(matrix[i][j]);
//
//		while (i - 1 >= 0 && j + 1 < cols)
//		{
//			i--;
//			j++;
//			output.push_back(matrix[i][j]);
//		}
//	}
//	return output;
//}

//////////////////////////////////////////////////////////////////////////
vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
{
	vector<int> nums;
	int m = matrix.size();
	if (m == 0) return nums;
	int n = matrix[0].size();
	if (n == 0) return nums;

	bool bXFlag = true;
	for (int i = 0; i < m + n; i++)
	{
		int pm = bXFlag ? m : n;
		int pn = bXFlag ? n : m;

		int x = (i < pm) ? i : pm - 1;
		int y = i - x;
		while (x >= 0 && y < pn)
		{
			nums.push_back(bXFlag ? matrix[x][y] : matrix[y][x]);
			x--;
			y++;
		}
		bXFlag = !bXFlag;
	}
	return nums;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& matrix)
{
	return findDiagonalOrder(matrix);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

