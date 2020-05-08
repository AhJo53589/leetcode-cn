
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        vector<vector<int>> m(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int ans = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '0') continue;
                m[i + 1][j + 1] = min(min(m[i][j + 1], m[i + 1][j]), m[i][j]) + 1;
                ans = max(ans, m[i + 1][j + 1]);
            }
        }

        return ans * ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<char>>& matrix)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maximalSquare(matrix);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
