
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int cnt = 0;
        queue<vector<int>> que;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    que.push({ i, j });
                }
                else if (grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }

        int ans = 0;
        vector<vector<int>> dd = { {0,1},{0,-1},{1,0},{-1,0} };
        while (!que.empty())
        {
            auto q = que.front();
            que.pop();

            for (auto d : dd)
            {
                int dx = q[0] + d[0];
                int dy = q[1] + d[1];
                if (dx < 0 || dx >= grid.size()) continue;
                if (dy < 0 || dy >= grid[0].size()) continue;
                if (grid[dx][dy] != 1) continue;
                grid[dx][dy] = grid[q[0]][q[1]] + 1;
                cnt--;
                que.push({ dx, dy });
                ans = grid[dx][dy] - 2;
            }
        }
        return (cnt == 0) ? ans : -1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.orangesRotting(grid);
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
