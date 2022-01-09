
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        vector<vector<bool>> flag(matrix.size() * 2, vector<bool>(matrix.size() + 1, false));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (flag[j][matrix[i][j]]) return false;
                flag[j][matrix[i][j]] = true;
                if (flag[matrix.size() + i][matrix[i][j]]) return false;
                flag[matrix.size() + i][matrix[i][j]] = true;
            }
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<vector<int>>& matrix)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.checkValid(matrix);
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
