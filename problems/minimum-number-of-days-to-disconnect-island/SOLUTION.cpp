
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int minDays(vector<vector<int>>& grid) {
        vi = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != 1) continue;

                int cntSide = 0;
                for (auto d : dd) {
                    int dx = d[0] + i;
                    int dy = d[1] + j;
                    if (dx < 0 || dx >= grid.size() || dy < 0 || dy >= grid[0].size()) continue;
                    cntSide += grid[dx][dy];
                }
                if (cntSide == 1) {
                    side1.push_back({ i,j });
                }
                if (cntSide == 2) {
                    side2.push_back({ i,j });
                }
            }
        }

        if (check(grid)) return 0;
        if (checkSide1(grid)) return 1;
        if (checkSide2(grid)) return 1;
        return 2;
    }

    bool check(vector<vector<int>>& grid) {
        vi = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

        int land = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !vi[i][j]) {
                    land++;
                    dfs(grid, i, j);
                }
            }
        }
        return land != 1;
    }

    void dfs(vector<vector<int>>& grid, int x, int y) {
        vi[x][y] = true;
        for (auto d : dd) {
            int dx = d[0] + x;
            int dy = d[1] + y;
            if (dx < 0 || dx >= grid.size() || dy < 0 || dy >= grid[0].size()) continue;
            if (grid[dx][dy] == 0) continue;
            if (vi[dx][dy]) continue;
            dfs(grid, dx, dy);
        }
    }

    bool checkSide1(vector<vector<int>>& grid) {
        for (auto& s : side1) {
            int x = s[0];
            int y = s[1];
            for (auto d : dd) {
                int dx = d[0] + x;
                int dy = d[1] + y;
                if (dx < 0 || dx >= grid.size() || dy < 0 || dy >= grid[0].size()) continue;
                if (grid[dx][dy] != 1) continue;
                grid[dx][dy] = 0;
                if (check(grid)) return true;
                grid[dx][dy] = 1;
            }
        }
        return false;
    }

    bool checkSide2(vector<vector<int>>& grid) {
        for (auto& s : side2) {
            int x = s[0];
            int y = s[1];
            for (auto d : dd) {
                int dx = d[0] + x;
                int dy = d[1] + y;
                if (dx < 0 || dx >= grid.size() || dy < 0 || dy >= grid[0].size()) continue;
                if (grid[dx][dy] != 1) continue;
                grid[x][y] = 0;
                if (check(grid)) return true;
                grid[x][y] = 1;
                break;
            }
        }
        return false;
    }

private:
    vector<vector<int>> dd = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    vector<vector<bool>> vi;
    vector<vector<int>> side1;
    vector<vector<int>> side2;
};

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        vi = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != 1) continue;

                vector<vector<int>> temp = { {i,j} };
                for (int k = 0; k < dd.size(); k++) {
                    auto d = dd[k];
                    int dx = d[0] + i;
                    int dy = d[1] + j;
                    if (dx < 0 || dx >= grid.size() || dy < 0 || dy >= grid[0].size()) continue;
                    if (grid[dx][dy] != 1) continue;
                    temp.push_back({ dx, dy });
                }
                if (temp.size() == 2) {
                    water.push_back(temp.back());
                }
                if (temp.size() == 3) {
                    water.push_back(temp.front());
                }
            }
        }

        if (check(grid)) return 0;
        for (auto& s : water) {
            grid[s[0]][s[1]] = 0;
            if (check(grid)) return 1;
            grid[s[0]][s[1]] = 1;

        }
        return 2;
    }

    bool check(vector<vector<int>>& grid) {
        vi = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

        int land = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !vi[i][j]) {
                    land++;
                    dfs(grid, i, j);
                }
            }
        }
        return land != 1;
    }

    void dfs(vector<vector<int>>& grid, int x, int y) {
        vi[x][y] = true;
        for (auto d : dd) {
            int dx = d[0] + x;
            int dy = d[1] + y;
            if (dx < 0 || dx >= grid.size() || dy < 0 || dy >= grid[0].size()) continue;
            if (grid[dx][dy] == 0) continue;
            if (vi[dx][dy]) continue;
            dfs(grid, dx, dy);
        }
    }

private:
    vector<vector<int>> dd = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    vector<vector<bool>> vi;
    vector<vector<int>> water;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorVectorT(grid);
    Solution sln;
    return sln.minDays(grid);
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
