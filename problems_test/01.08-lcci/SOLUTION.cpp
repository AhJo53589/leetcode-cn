
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        vector<bool> row(matrix.size(), false);
        vector<bool> col(matrix[0].size(), false);

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] != 0) continue;
                row[i] = true;
                col[j] = true;
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (!row[i] && !col[j]) continue;
                matrix[i][j] = 0;
            }
        }
    }
};

//////////////////////////////////////////////////////////////////////////
void _solution_run(vector<vector<int>>& matrix)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.setZeroes(matrix);
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
