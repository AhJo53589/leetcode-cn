
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minCost(vector<vector<int>>& grid)
    {
        vector<vector<int>> dd = { {}, {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        vector<vector<bool>> vi(grid.size(), vector<bool>(grid[0].size(), false));
        queue<vector<int>> cq;
        queue<vector<int>> nq;
        int ans = 0;
        cq.push({ 0, 0 });

        while (!cq.empty() || !nq.empty())
        {
            while (!cq.empty())
            {
                auto q = cq.front();
                cq.pop();
                int x = q[0];
                int y = q[1];
                if ((x < 0 || x >= grid.size()) || (y < 0 || y >= grid[0].size())) continue;
                if (vi[x][y]) continue;
                if (x == grid.size() - 1 && y == grid[0].size() - 1) return ans;
                vi[x][y] = true;

                for (int i = 1; i < dd.size(); i++)
                {
                    int dx = x + dd[i][0];
                    int dy = y + dd[i][1];
                    auto& sq = (i == grid[x][y]) ? cq : nq;
                    sq.push({ dx, dy });
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
