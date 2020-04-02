


//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    void aliveReport(vector<vector<int>>& board, int x, int y)
    {
        for (int i = max(0, x - 1); i < min((int)board.size(), x + 2); i++)
        {
            for (int j = max(0, y - 1); j < min((int)board[0].size(), y + 2); j++)
            {
                if (i == x && j == y) continue;
                board[i][j] += (board[i][j] > 0) ? 1 : -1;
            }
        }
    }

    void gameOfLife(vector<vector<int>>& board)
    {
        if (board.empty() || board[0].empty()) return;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] <= 0) continue;
                aliveReport(board, i, j);
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                int& x = board[i][j];
                x = (x == 2 + 1 || x == 3 + 1 || x == -3) ? 1 : 0;
            }
        }
    }
};


//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countAlive(vector<vector<int>>& board, int x, int y)
    {
        int cnt = 0;
        for (int i = max(0, x - 1); i < min((int)board.size(), x + 2); i++)
        {
            for (int j = max(0, y - 1); j < min((int)board[0].size(), y + 2); j++)
            {
                if (i == x && j == y) continue;
                cnt += (i < x || (i == x && j < y)) ? ((0b10 & board[i][j]) != 0) : ((0b01 & board[i][j]) != 0);
            }
        }
        return cnt;
    }

    void gameOfLife(vector<vector<int>>& board)
    {
        if (board.empty() || board[0].empty()) return;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                int cnt = countAlive(board, i, j);
                board[i][j] <<= 1;
                if ((board[i][j] & 0b10) != 0)
                {
                    board[i][j] |= (cnt == 2 || cnt == 3);
                }
                else
                {
                    board[i][j] |= (cnt == 3);
                }
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                board[i][j] &= 1;
            }
        }
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& board)
{
    printVectorVectorT(board);
    Solution2 sln;
    sln.gameOfLife(board);
    printVectorVectorT(board);
    return board;
}

//#define USE_SOLUTION_CUSTOM
//void _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}

