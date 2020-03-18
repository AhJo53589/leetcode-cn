
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
	{
		int x = -1;
		int y = -1;
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[i].empty()) break;
			if (matrix[i][0] > target) break;
			x = i;
		}
		if (x == -1) return false;
		for (int j = 0; j < matrix[x].size(); j++)
		{
			if (matrix[x][j] > target) break;
			if (matrix[x][j] == target) return true;
		}
		return false;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<vector<int>>& matrix, int target)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.searchMatrix(matrix, target);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
