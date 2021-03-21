
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int, int>> que;
        que.push({0, 0});

        while (!que.empty()) {
            auto[i, j] = que.front();
            que.pop();

            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }

            if (i + 1 != matrix.size()) {
                que.push({i + 1, j});                
            }
            if (j + 1 != matrix[0].size()) {
                que.push({i, j + 1});
            }
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                matrix[i][j] = (matrix[i][0] == 0 || matrix[0][j] == 0) ? 0 : matrix[i][j];
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            matrix[i][0] = (matrix[0][0] == 0) ? 0 : matrix[i][0];
        }
        for (int j = 1; j < matrix[0].size(); j++) {
            matrix[0][j] = (matrix[0][0] == 0) ? 0 : matrix[0][j];
        }
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& matrix)
{
	int caseNo = 4;
	static int caseCnt = 0;
	if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	sln.setZeroes(matrix);
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
