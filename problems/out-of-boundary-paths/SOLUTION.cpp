
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;
        const int mod = 1e9 + 7;

        vector<vector<int>> grid(m, vector<int>(n, 0));
        grid[startRow][startColumn] = 1;

        vector<vector<int>> dd = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        while(maxMove-- > 0) {
            vector<vector<int>> grid_new(m, vector<int>(n, 0));
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    for (auto d : dd) {
                        int dx = i + d[0];
                        int dy = j + d[1];
                        if (dx < 0 || dx >= grid.size() || dy < 0 || dy >= grid[0].size()) {
                            ans += grid[i][j];
                            ans %= mod;
                            continue;
                        }
                        grid_new[dx][dy] += grid[i][j];
                        grid_new[dx][dy] %= mod;
                    }
                }
            }
            swap(grid, grid_new);
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int m, int n, int maxMove, int startRow, int startColumn)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findPaths(m, n, maxMove, startRow, startColumn);
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
