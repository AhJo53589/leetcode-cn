
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<vector<pair<int, int>>> lines;
        transToLines(grid, lines);
        for (auto& line : lines) {
            rotate(line.begin(), line.begin() + k % line.size(), line.end());
        }
        return transToGrid(grid, lines);
    }

    void transToLines(vector<vector<int>>& grid, vector<vector<pair<int, int>>>& lines) {
        for (int lv = 0; lv < grid.size() / 2 && lv < grid[0].size() / 2; lv++) {
            vector<pair<int, int>> line;
            int i = lv;
            int j = lv;
            int d = 0;
            while (true) {
                line.emplace_back(i, j);
                d += (i + dd[d][0] == grid.size() - lv || i + dd[d][0] < lv
                    || j + dd[d][1] == grid[0].size() - lv || j + dd[d][1] < lv);
                if (d == dd.size()) break;
                i += dd[d][0];
                j += dd[d][1];
            }
            line.pop_back();
            lines.emplace_back(line);
        }
    }

    vector<vector<int>> transToGrid(vector<vector<int>>& grid, vector<vector<pair<int, int>>>& lines) {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        for (int lv = 0; lv < grid.size() / 2 && lv < grid[0].size() / 2; lv++) {
            int i = lv;
            int j = lv;
            int d = 0;
            for (auto [di, dj] : lines[lv]) {
                ans[i][j] = grid[di][dj];
                d += (i + dd[d][0] == grid.size() - lv || i + dd[d][0] < lv
                    || j + dd[d][1] == grid[0].size() - lv || j + dd[d][1] < lv);
                if (d == dd.size()) break;
                i += dd[d][0];
                j += dd[d][1];
            }
        }
        return ans;
    }

private:
    vector<vector<int>> dd = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& grid, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.rotateGrid(grid, k);
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
