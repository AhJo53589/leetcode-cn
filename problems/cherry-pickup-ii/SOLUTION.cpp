
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        if (grid[0].empty()) return 0;

        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), 0)));
        dp[0][0][grid[0].size() - 1] = grid[0][0] + grid[0].back() + 1;
        
        int ans = 0;
        for (int i = 0; i < grid.size() - 1; i++) {

            for (int a = 0; a < grid[0].size(); a++) {
                for (int b = a; b < grid[0].size(); b++) {
                    if (dp[i][a][b] == 0) continue;

                    for (int ar = max(a - 1, 0); ar < min(a + 2, (int)grid[0].size()); ar++) {
                        for (int br = max(b - 1, 0); br < min(b + 2, (int)grid[0].size()); br++) {
                            int art = (ar < br) ? ar : br;
                            int brt = (ar < br) ? br : ar;

                            int newVal = dp[i][a][b] + grid[i + 1][art] + grid[i + 1][brt];
                            newVal -= (art == brt) ? grid[i + 1][art] : 0;
                            dp[i + 1][art][brt] = max(dp[i + 1][art][brt], newVal);
                        }
                    }
                }
            }
        }

        for (int a = 0; a < grid[0].size(); a++) {
            for (int b = a; b < grid[0].size(); b++) {
                ans = max(ans, dp.back()[a][b]);
            }
        }

        return ans - 1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorVectorT(grid);

    Solution sln;
    return sln.cherryPickup(grid);
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
