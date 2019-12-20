
int getp(vector<vector<char>>& b, vector<vector<int>>& dd, int x, int y)
{
    int cnt = 0;
    for (auto d : dd)
    {
        int dx = x;
        int dy = y;
        while (true)
        {
            dx += d[0];
            dy += d[1];
            if (dx < 0 || dx >= b.size()) break;
            if (dy < 0 || dy >= b[0].size()) break;
            if (b[dx][dy] == 'B') break;
            if (b[dx][dy] == 'p') 
            {
                cnt++;
                break;
            }  
        }
    }
    return cnt;
}

//////////////////////////////////////////////////////////////////////////
int numRookCaptures(vector<vector<char>>& board)
{
    vector<vector<int>> dd = {{0,1},{0,-1},{1,0},{-1,0}};

    for (int x = 0; x < board.size(); x++)
    {
        for (int y = 0; y < board[0].size(); y++)
        {
            if (board[x][y] != 'R') continue;
            return getp(board, dd, x, y);
        }
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<char>>& board)
{
	return numRookCaptures(board);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/available-captures-for-rook/tests.txt";
}

