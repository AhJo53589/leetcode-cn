
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid)
    {
        vector<vector<int>> dd = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                for (auto& d : dd)
                {
                    int di = i + d[0];
                    int dj = j + d[1];
                    if (di < 0 || di >= grid.size() || dj < 0 || dj >= grid[0].size())
                    {
                        ans += grid[i][j];
                    }
                    else
                    {
                        ans += max(grid[i][j] - grid[di][dj], 0);
                    }
                }
                ans += 2 * (grid[i][j] > 0);
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.surfaceArea(grid);
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
