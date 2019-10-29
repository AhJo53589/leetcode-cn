
//bool searchTarget(vector<vector<int>>& matrix, int i, int j, int target)
//{
//	if (i >= matrix.size()) return false;
//	if (j >= matrix[i].size()) return false;
//
//	if (matrix[i][j] == target) return true;
//	if (matrix[i][j] < target)
//	{
//		if (searchTarget(matrix, i + 1, j, target) || searchTarget(matrix, i, j + 1, target))
//		{
//			return true;
//		}
//	}
//	return false;
//}

//bool searchMatrix(vector<vector<int>>& matrix, int target) 
//{
//	if (matrix.size() == 0) return false;
//	return searchTarget(matrix, 0, 0, target);
//}

//////////////////////////////////////////////////////////////////////////
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int r = matrix.size();
	if (r == 0) return false;

	int c = matrix[0].size();
	for (int i = 0, j = c - 1; i<r && j>-1;)
	{
		if (target < matrix[i][j])
		{
			j--;
		}
		else if (target > matrix[i][j])
		{
			i++;
		}
		else
		{
			return true;
		}
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<vector<int>>& matrix, int target)
{
	return searchMatrix(matrix,target);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
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
	return "../../problems/search-a-2d-matrix-ii/tests.txt";
}

