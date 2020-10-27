
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        ans = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), -1));
        row = vector<bool>(matrix.size(), false);
        col = vector<bool>(matrix[0].size(), false);

        vector<vector<int>> seq(matrix.size() * matrix[0].size());
        int k = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                seq[k++] = vector<int>{ matrix[i][j], i, j };
            }
        }
        sort(seq.begin(), seq.end());

        for (int i = 0; i < seq.size(); i++) {
            int x = seq[i][1];
            int y = seq[i][2];
            if (ans[x][y] != -1) continue;
            vi_clear(matrix);
            vi_fill(matrix, x, y);
            int t = calcRank(matrix, matrix[x][y]);
            setRank(matrix, t);
        }
        return ans;
    }

    void vi_fill(vector<vector<int>>& matrix, int x, int y) {
        ans[x][y] = 0;
        row[x] = true;
        col[y] = true;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][y] != matrix[x][y] || ans[i][y] != -1 || row[i]) continue;
            vi_fill(matrix, i, y);
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[x][j] != matrix[x][y] || ans[x][j] != -1 || col[j]) continue;
            vi_fill(matrix, x, j);
        }
    }

    void vi_clear(vector<vector<int>>& matrix) {
        row = vector<bool>(matrix.size(), false);
        col = vector<bool>(matrix[0].size(), false);
    }

    int calcRank(vector<vector<int>>& matrix, int val) {
        int t = 1;
        for (int i = 0; i < row.size(); i++) {
            if (!row[i]) continue;
            for (int j = 0; j < col.size(); j++) {
                if (!col[j]) continue;
                t = (matrix[i][j] < val) ? max(t, ans[i][j] + 1) : t;
            }
        }
        return t;
    }

    void setRank(vector<vector<int>>& matrix, int rank) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans[i][j] = (ans[i][j] == 0) ? rank : ans[i][j];
            }
        }
    }

private:
    vector<vector<int>> ans;
    vector<bool> row;
    vector<bool> col;
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& matrix)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.matrixRankTransform(matrix);
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
