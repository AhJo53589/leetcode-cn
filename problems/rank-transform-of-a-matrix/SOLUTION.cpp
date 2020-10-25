
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> seq(matrix.size() * matrix[0].size());
        int k = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                seq[k++] = vector<int>{ matrix[i][j], i, j };
            }
        }
        sort(seq.begin(), seq.end());

        for (int i = 0; i < seq.size(); i++) {
            calc(matrix, ans, seq[i][1], seq[i][2]);
        }
        return ans;
    }

    void calc(vector<vector<int>>& matrix, vector<vector<int>>& ans, int x, int y) {
        int t = 1;
        vector<vector<int>> same;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][y] > matrix[x][y]) continue;
            if (matrix[i][y] == matrix[x][y]) {
                same.push_back({ i, y });
                t = max(t, ans[i][y]);
            }
            else {
                t = max(t, ans[i][y] + 1);
            }
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[x][j] > matrix[x][y]) continue;
            if (matrix[x][j] == matrix[x][y]) {
                same.push_back({ x, j });
                t = max(t, ans[x][j]);
            }
            else {
                t = max(t, ans[x][j] + 1);
            }
        }
        set<vector<int>> vi;
        queue<vector<int>> que;
        for (auto s : same) {
            que.push({ s[0], s[1] });
            vi.insert({ s[0], s[1] });
            //ans[s[0]][s[1]] = t;
        }
        while (!que.empty()) {
            auto q = que.front();
            que.pop();


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
