
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bitset<9> getPossibleStatus(int x, int y)
    {
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }

    vector<int> getNext(vector<vector<char>>& board)
    {
        vector<int> ret;
        int minCnt = 10;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.') continue;
                auto cur = getPossibleStatus(i, j);
                if (cur.count() >= minCnt) continue;
                ret = { i, j };
                minCnt = cur.count();
            }
        }
        return ret;
    }

    void fillNum(int x, int y, int n, bool fillFlag)
    {
        bitset<9> pick(1 << n);
        rows[x] = (fillFlag) ? (rows[x] | pick) : (rows[x] ^ pick);
        cols[y] = (fillFlag) ? (cols[y] | pick) : (cols[y] ^ pick);
        cells[x / 3][y / 3] = (fillFlag) ? (cells[x / 3][y / 3] | pick) : (cells[x / 3][y / 3] ^ pick);
    }
    
    bool dfs(vector<vector<char>>& board, int cnt)
    {
        if (cnt == 0) return true;

        auto next = getNext(board);
        auto bits = getPossibleStatus(next[0], next[1]);
        for (int n = 0; n < bits.size(); n++)
        {
            if (!bits.test(n)) continue;
            fillNum(next[0], next[1], n, true);
            board[next[0]][next[1]] = n + '1';
            if (dfs(board, cnt - 1)) return true;
            board[next[0]][next[1]] = '.';
            fillNum(next[0], next[1], n, false);
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) 
    {
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        int cnt = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cnt += (board[i][j] == '.');
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '1';
                rows[i] |= (1 << n);
                cols[j] |= (1 << n);
                cells[i / 3][j / 3] |= (1 << n);
            }
        }
        dfs(board, cnt);
    }

    //void printStatus()
    //{
    //    cout << endl << "rows:" << endl;
    //    for (auto& b : rows)
    //    {
    //        for (int i = 0; i < b.size(); i++) cout << setw(4) << b[i];
    //        cout << endl;
    //    }
    //    cout << endl << "cols:" << endl;
    //    for (auto& b : cols)
    //    {
    //        for (int i = 0; i < b.size(); i++) cout << setw(4) << b[i];
    //        cout << endl;
    //    }
    //    cout << endl << "cells:" << endl;
    //    for (auto& bb : cells) for (auto& b : bb)
    //    {
    //        for (int i = 0; i < b.size(); i++) cout << setw(4) << b[i];
    //        cout << endl;
    //    }
    //    cout << endl;
    //}

private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;
};

//////////////////////////////////////////////////////////////////////////
vector<vector<char>> _solution_run(vector<vector<char>>& board)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << convert<string>(board) << endl;
    Solution sln;
    sln.solveSudoku(board);
    return board;
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
