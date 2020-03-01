

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minCost(vector<vector<int>>& grid)
    {
        vector<vector<int>> dd = { {}, {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        vector<vector<int>> vi(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        queue<vector<int>> cq;
        queue<vector<int>> nq;
        int ans = 0;
        cq.push({ 0, 0 });
        vi[0][0] = 0;

        while (!cq.empty() || !nq.empty())
        {
            while (!cq.empty())
            {
                auto q = cq.front();
                cq.pop();
                int x = q[0];
                int y = q[1];
                if (vi[x][y] < ans) continue;
                if (x == grid.size() - 1 && y == grid[0].size() - 1) return ans;

                for (int i = 1; i < dd.size(); i++)
                {
                    int dx = x + dd[i][0];
                    int dy = y + dd[i][1];
                    if ((dx < 0 || dx >= grid.size()) || (dy < 0 || dy >= grid[0].size())) continue;
                    if (vi[dx][dy] <= ans) continue;

                    auto& sq = (i == grid[x][y]) ? cq : nq;
                    sq.push({ dx, dy });
                    vi[dx][dy] = (i == grid[x][y]) ? ans : ans + 1;
                }
            }
            swap(cq, nq);
            ans++;
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
    return sln.minCost(grid);
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
