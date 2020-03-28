
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid)
    {
        queue<pair<int, int>> que;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0) continue;
                que.push({ i,j });
            }
        }
        if (que.empty() || que.size() == grid.size() * grid[0].size()) return -1;

        int ans = 0;
        vector<vector<int>> dd = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        while (!que.empty())
        {
            auto q = que.front();
            que.pop();
            ans = grid[q.first][q.second];

            for (auto d : dd)
            {
                int dx = q.first + d[0];
                int dy = q.second + d[1];
                if (dx < 0 || dx >= grid.size()) continue;
                if (dy < 0 || dy >= grid[0].size()) continue;
                if (grid[dx][dy] != 0) continue;
                grid[dx][dy] = ans + 1;
                que.push({ dx, dy });
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

    Solution sln;
    return sln.maxDistance(grid);
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
