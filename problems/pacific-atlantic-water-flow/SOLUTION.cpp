
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {      
        vector<vector<int>> dd = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = heights.size();
        int n = heights[0].size();
        const int Pacific = 0;
        const int Atlantic = 1;
        vector<vector<int>> vi(m, vector<int>(n, 0));

        queue<pair<int, int>> que;
        for (int i = 0; i < m; i++) {
            push(que, vi, i, 0, Pacific);
            push(que, vi, i, n - 1, Atlantic);
        }
        for (int j = 0; j < n; j++) {
            push(que, vi, 0, j, Pacific);
            push(que, vi, m - 1, j, Atlantic);
        }

        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            
            for (auto& d : dd) {
                int dx = x + d[0];
                int dy = y + d[1];
                if (dx < 0 || dx >= m || dy < 0 || dy >= n) continue;
                if (heights[x][y] > heights[dx][dy]) continue;

                if (check(vi, x, y, Pacific) && !check(vi, dx, dy, Pacific)) {
                    push(que, vi, dx, dy, Pacific);
                }
                if (check(vi, x, y, Atlantic) && !check(vi, dx, dy, Atlantic)) {
                    push(que, vi, dx, dy, Atlantic);
                }
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vi[i][j] == 3) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    bool check(vector<vector<int>>& vi, int x, int y, int mask) {
        return (vi[x][y] & (1 << mask)) != 0;
    }

    void push(queue<pair<int, int>>& que, vector<vector<int>>& vi, int x, int y, int mask) {
        vi[x][y] |= (1 << mask);
        que.push({x, y});
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& heights)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.pacificAtlantic(heights);
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
