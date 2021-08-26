
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo = 0;
        int hi = cells.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            vector<vector<int>> board = vector<vector<int>>(row, vector<int>(col, 0));
            for (int i = 0; i < cells.size() && i < mid; i++) {
                int x = cells[i][0] - 1;
                int y = cells[i][1] - 1;
                board[x][y] = 1;
            }

            queue<pair<int, int>> que;
            for (int i = 0; i < board[0].size(); i++) {
                if (board[0][i] == 0) {
                    board[0][i] = 1;
                    que.push({ 0, i });
                }
            }

            bool found = false;
            while (!que.empty() && !found) {
                auto [x, y] = que.front();
                que.pop();

                for (auto d : dd) {
                    int dx = x + d[0];
                    int dy = y + d[1];
                    if (dx < 0 || dx >= board.size()) continue;
                    if (dy < 0 || dy >= board[0].size()) continue;
                    if (board[dx][dy] == 1) continue;
                    que.push({ dx, dy });
                    board[dx][dy] = 1;

                    if (dx == row - 1) {
                        found = true;
                        break;
                    }
                }
            }

            if (found) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        return lo - 1;
    }

private:
    vector<vector<int>> dd = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int row, int col, vector<vector<int>>& cells)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.latestDayToCross(row, col, cells);
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
