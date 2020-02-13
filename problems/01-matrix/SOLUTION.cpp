
//vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
//{
//	int rows = matrix.size();
//	if (rows == 0)
//		return matrix;
//	int cols = matrix[0].size();
//	vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX - 100000));
//
//	//First pass: check for left and top
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			if (matrix[i][j] == 0)
//				dist[i][j] = 0;
//			else {
//				if (i > 0)
//					dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
//				if (j > 0)
//					dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
//			}
//		}
//	}
//
//	//Second pass: check for bottom and right
//	for (int i = rows - 1; i >= 0; i--) {
//		for (int j = cols - 1; j >= 0; j--) {
//			if (i < rows - 1)
//				dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
//			if (j < cols - 1)
//				dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
//		}
//	}
//
//	return dist;
//}

int getMin(vector<vector<int>>& matrix, int x, int y, int x_Size, int y_Size)
{
	if (matrix[x][y] == 0) return 0;
	int iMin = INT_MAX;
	if (x + 1 < x_Size) iMin = min(iMin, matrix[x + 1][y]);
	if (x - 1 >= 0) iMin = min(iMin, matrix[x - 1][y]);
	if (y + 1 < y_Size) iMin = min(iMin, matrix[x][y + 1]);
	if (y - 1 >= 0) iMin = min(iMin, matrix[x][y - 1]);
	return iMin;
}


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
{
	int x_Size = matrix.size();
	if (x_Size == 0) return matrix;
	int y_Size = matrix[0].size();
	if (y_Size == 0) return matrix;

	queue<pair<int, int>> q;
	for (int x = 0; x < x_Size; x++)
	{
		for (int y = 0; y < y_Size; y++)
		{
			if (getMin(matrix, x, y, x_Size, y_Size) == 0)
			{
				if (matrix[x][y] == 1)
				{
					if (x + 1 < x_Size) q.push(make_pair(x + 1, y));
					if (x - 1 >= 0) q.push(make_pair(x - 1, y));
					if (y + 1 < y_Size) q.push(make_pair(x, y + 1));
					if (y - 1 >= 0) q.push(make_pair(x, y - 1));
				}
				continue;
			}
			matrix[x][y] = INT_MAX;
		}
	}

	int iMin = 0;
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();

		int x = p.first;
		int y = p.second;
		if (matrix[x][y] != INT_MAX) continue;
		if (matrix[x][y] <= iMin) continue;
		iMin = getMin(matrix, p.first, p.second, x_Size, y_Size);
		matrix[x][y] = iMin + 1;

		if (x + 1 < x_Size) q.push(make_pair(x + 1, y));
		if (x - 1 >= 0) q.push(make_pair(x - 1, y));
		if (y + 1 < y_Size) q.push(make_pair(x, y + 1));
		if (y - 1 >= 0) q.push(make_pair(x, y - 1));
	}
	return matrix;
}


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& matrix)
{
	return updateMatrix(matrix);
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

