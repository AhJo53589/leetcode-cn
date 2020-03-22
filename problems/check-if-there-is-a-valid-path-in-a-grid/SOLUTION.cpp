
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) 
    {
        if (grid.size() == 1 && grid[0].size() == 1) return true;

        vector<vector<int>> dpath = { {}, {1, 3}, {0, 2}, {3, 2}, {2, 1}, {0, 3}, {0, 1} };
        vector<vector<int>> dd = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

        queue<int> que;
        for (auto dir_cur : dpath[grid[0][0]])
        {
            if (dir_cur == 0 || dir_cur == 3) continue;
            int x = 0;
            int y = 0;

            while (true)
            {
                x += dd[dir_cur][0];
                y += dd[dir_cur][1];
                if (x < 0 || x >= grid.size()) break;
                if (y < 0 || y >= grid[0].size()) break;

                bool enter = false;
                int dir_nxt = -1;
                for (auto& path : dpath[grid[x][y]])
                {
                    if ((dir_cur + 2) % 4 == path)
                    {
                        enter = true;
                        continue;
                    }
                    dir_nxt = path;
                }
                if (!enter) return false;

                if (x == grid.size() - 1 && y == grid[0].size() - 1) return true;
                dir_cur = dir_nxt;
            }
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<vector<int>>& grid)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.hasValidPath(grid);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string    
//{
//    return {};
//}
