
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bitset<9>> row(9);
        vector<bitset<9>> col(9);
        vector<bitset<9>> grid(9);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') continue;
                int k = (i / 3) * 3 + (j / 3);
                int n = (int)(board[i][j] - '1');
                
                if (row[i].test(n)) return false;
                if (col[j].test(n)) return false;
                if (grid[k].test(n)) return false;
                row[i].set(n);
                col[j].set(n);
                grid[k].set(n);
            }
        }

        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<vector<char>>& board)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.isValidSudoku(board);
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
