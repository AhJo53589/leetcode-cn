
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> que;
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                if (rooms[i][j] != 0) continue;
                que.push({i, j});
            }
        }

        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();

            for (auto d : dd) {
                int dx = x + d[0];
                int dy = y + d[1];
                if (dx < 0 || dx >= rooms.size()) continue;
                if (dy < 0 || dy >= rooms[0].size()) continue;
                if (rooms[dx][dy] <= rooms[x][y] + 1) continue;

                rooms[dx][dy] = rooms[x][y] + 1;
                que.push({dx, dy});
            }
        }
    }

private:
    vector<vector<int>> dd = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
};

//////////////////////////////////////////////////////////////////////////
void _solution_run(vector<vector<int>>& rooms)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.wallsAndGates(rooms);
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
