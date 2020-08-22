
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        mine = vector<vector<int>>(board.size(), vector<int>(board[0].size(), -1));
        dfs(board, click[0], click[1]);
        return board;
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }
        if (board[x][y] != 'E') return;

        int cnt = getCnt(board, x, y);
        if (cnt != 0) {
            board[x][y] = '0' + cnt;
            return;
        }

        board[x][y] = 'B';
        for (int i = max(0, x - 1); i < min((int)board.size(), x + 2); i++) {
            for (int j = max(0, y - 1); j < min((int)board[0].size(), y + 2); j++) {
                dfs(board, i, j);
            }
        }
    }

    int getCnt(vector<vector<char>>& board, int x, int y) {
        if (mine[x][y] != -1) return mine[x][y];

        int cnt = 0;
        for (int i = max(0, x - 1); i < min((int)board.size(), x + 2); i++) {
            for (int j = max(0, y - 1); j < min((int)board[0].size(), y + 2); j++) {
                cnt += (board[i][j] == 'M');
            }
        }
        mine[x][y] = cnt;
        return cnt;
    }

private:
    vector<vector<int>> mine;
};

//////////////////////////////////////////////////////////////////////////
vector<vector<char>> _solution_run(vector<vector<char>>& board, vector<int>& click)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.updateBoard(board, click);
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
