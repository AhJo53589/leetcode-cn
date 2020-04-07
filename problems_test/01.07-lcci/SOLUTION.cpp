
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int temp;
        int end = matrix.size() - 1;
        float mid_line = end / 2;
        for (int i = 0; i <= end; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i <= end; i++)
        {
            for (int j = 0; j <= mid_line; j++)
            {
                swap(matrix[i][j], matrix[i][end - j]);
            }
        }
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& matrix)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	sln.rotate(matrix);
    return matrix;
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
