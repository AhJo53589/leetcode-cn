
//////////////////////////////////////////////////////////////////////////
struct DSU {
    DSU(int n) : data(n, -1) {}

    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;

        if (data[y] < data[x]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    int size(int x) {
        return -data[root(x)];
    }

    std::vector<int> data;
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        ans = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), -1));
        row = vector<bool>(matrix.size(), false);
        col = vector<bool>(matrix[0].size(), false);
        rank_row = vector<int>(matrix.size(), 0);
        rank_col = vector<int>(matrix[0].size(), 0);

        seq = vector<vector<int>>(matrix.size() * matrix[0].size());
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
            vi_fill(seq, i, x, y);
            int t = calcRank(matrix, matrix[x][y]);
            setRank(matrix, t);
        }
        return ans;
    }

    void vi_fill(vector<vector<int>>& seq, int i, int x, int y) {
        vi.push_back({ x, y });
        ans[x][y] = 0;
        row[x] = true;
        col[y] = true;
        for (int j = 1; i + j < seq.size() && seq[i + j][0] == seq[i][0]; j++) {
            int dx = seq[i + j][1];
            int dy = seq[i + j][2];
            if (ans[dx][dy] != -1) continue;
            if (!row[dx] && !col[dy]) continue;
            vi_fill(seq, i, dx, dy);
        }
    }

    void vi_clear(vector<vector<int>>& matrix) {
        //row = vector<bool>(matrix.size(), false);
        //col = vector<bool>(matrix[0].size(), false);
        vi = vector<vector<int>>();
    }

    int calcRank(vector<vector<int>>& matrix, int val) {
        int t = 1;
        for (int i = 0; i < row.size(); i++) {
            if (!row[i]) continue;
            row[i] = false;
            t = max(t, rank_row[i] + 1);
        }
        for (int j = 0; j < col.size(); j++) {
            if (!col[j]) continue;
            col[j] = false;
            t = max(t, rank_col[j] + 1);
        }
        return t;
    }

    void setRank(vector<vector<int>>& matrix, int rank) {
        for (auto p : vi) {
            ans[p[0]][p[1]] = rank;
            rank_row[p[0]] = rank;
            rank_col[p[1]] = rank;
        }
    }

private:
    vector<vector<int>> ans;
    vector<vector<int>> seq;
    vector<bool> row;
    vector<bool> col;
    vector<vector<int>> vi;
    vector<int> rank_row;
    vector<int> rank_col;
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
