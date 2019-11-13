
//vector<int> spiralOrder(vector<vector<int> > &matrix) {
//	if (matrix.empty() || matrix[0].empty()) return {};
//	int m = matrix.size(), n = matrix[0].size();
//	vector<int> res;
//	int c = m > n ? (n + 1) / 2 : (m + 1) / 2;
//	int p = m, q = n;
//	for (int i = 0; i < c; ++i, p -= 2, q -= 2) {
//		for (int col = i; col < i + q; ++col)
//			res.push_back(matrix[i][col]);
//		for (int row = i + 1; row < i + p; ++row)
//			res.push_back(matrix[row][i + q - 1]);
//		if (p == 1 || q == 1) break;
//		for (int col = i + q - 2; col >= i; --col)
//			res.push_back(matrix[i + p - 1][col]);
//		for (int row = i + p - 2; row > i; --row)
//			res.push_back(matrix[row][i]);
//	}
//	return res;
//}


//////////////////////////////////////////////////////////////////////////
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> nums;
	int m = matrix.size();
	if (m == 0) return nums;
	int n = matrix[0].size();
	if (n == 0) return nums;

	// 0 == →, 1 == ↓, 2 == ←, 3 == ↑
	int iDirection = 0;
	int iSize = m * n;
	int x = 0;
	int y = -1;

	while (nums.size() < iSize)
	{
		int iCount = 1;
		int iMaxCount = (iDirection % 2 == 0) ? n : m;
		int iStepX = (iDirection % 2 == 0) ? 0 : (iDirection / 2 == 0) ? 1 : -1;
		int iStepY = (iDirection % 2 == 1) ? 0 : (iDirection / 2 == 0) ? 1 : -1;

		while (iCount <= iMaxCount)
		{
			x = x + iStepX;
			y = y + iStepY;
			nums.push_back(matrix[x][y]);
			iCount++;
		}
		if (iDirection % 2 == 0) m--;
		else n--;

		iDirection = (iDirection + 1) % 4;
	}

	return nums;
}


//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& matrix)
{
	return spiralOrder(matrix);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
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
	return "../../problems/spiral-matrix/tests.txt";
}

