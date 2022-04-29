
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }

    Node* build(vector<vector<int>>& grid, int x, int y, int len) {
        int check = grid[x][y];
        for (int i = x; i < x + len && check != -1; i++) {
            for (int j = y; j < y + len && check != -1; j++) {
                check = (check != grid[i][j]) ? -1 : grid[i][j];
            }
        }

        if (check == -1) {
            len /= 2;
            Node* _topLeft = build(grid, x, y, len);
            Node* _topRight = build(grid, x, y + len, len);
            Node* _bottomLeft = build(grid, x + len, y, len);
            Node* _bottomRight = build(grid, x + len, y + len, len);
            return new Node(true, false, _topLeft, _topRight, _bottomLeft, _bottomRight);
        }

        return new Node(check == 1, true);
    }
};

//////////////////////////////////////////////////////////////////////////
Node* _solution_run(vector<vector<int>>& grid)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.construct(grid);
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
