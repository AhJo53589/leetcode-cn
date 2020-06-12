
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int i = 0;
        int j = matrix[0].size() - 1;
        while (j >= 0 && i < matrix.size()) {
            if (target == matrix[i][j]) return true;
            if (target < matrix[i][j]) {
                j--;
            }
            else {
                i++;
            }
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
	return sln.findNumberIn2DArray(matrix, target);
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
