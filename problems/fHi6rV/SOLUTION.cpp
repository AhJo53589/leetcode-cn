
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int flipChess(vector<string>& chessboard) {
        int ans = 0;
        for (int i = 0; i < chessboard.size(); i++) {
            for (int j = 0; j < chessboard[0].size(); j++) {
                if (chessboard[i][j] != '.') continue;
                vector<string> board(chessboard);
                board[i][j] = 'X';
                ans = max(ans, flip(board, i, j));
            }
        }
        return ans;
    }

    int flip(vector<string> &board, int x, int y) {
        int cnt = 0;
        for (auto& d : dd) {
            auto pos = flipLine(board, x, y, d);
            cnt += pos.size();
            for (auto& p : pos) {
                cnt += flip(board, p.first, p.second);
            }
        }
        return cnt;
    }

    vector<pair<int, int>> flipLine(vector<string>& board, int dx, int dy, vector<int>& d) {
        vector<pair<int, int>> pos;
        while (true) {
            dx += d[0];
            dy += d[1];
            if (dx < 0 || dx >= board.size()) break;
            if (dy < 0 || dy >= board[0].size()) break;
            if (board[dx][dy] == '.') break;
            if (board[dx][dy] == 'X') break;

            pos.emplace_back(dx, dy);
        }
        return pos;
    }

private:
    vector<vector<int>> dd = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1,-1}, {-1, 0}, {-1, 1} };
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& chessboard)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.flipChess(chessboard);
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
