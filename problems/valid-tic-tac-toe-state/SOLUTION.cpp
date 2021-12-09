
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cnt = 0;
        for (auto& s : board) {
            for (auto& c : s) {
                cnt += (c == 'X');
                cnt -= (c == 'O');
            }
        }

        int win[128]{};
        for (int i = 0; i < 3; i++) {
            ++win[board[i][0] | board[i][1] | board[i][2]];
            ++win[board[0][i] | board[1][i] | board[2][i]];
        }
        ++win[board[0][0] | board[1][1] | board[2][2]];
        ++win[board[2][0] | board[1][1] | board[0][2]];

        return cnt == 1 && !win['O'] || cnt == 0 && !win['X'];
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<string>& board)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.validTicTacToe(board);
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
