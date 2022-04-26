
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int x = 0;
        int y = 0;
        int z = 0;
        for (int j = 0; j < grid.size(); j++) {
            int y_max = 0;
            int z_max = 0;
            for (int i = 0; i < grid.size(); i++) {
                x += (grid[i][j] > 0);
                y_max = max(y_max, grid[i][j]);
                z_max = max(z_max, grid[j][i]);
            }
            y += y_max;
            z += z_max;
        }
        return x + y + z;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.projectionArea(grid);
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
