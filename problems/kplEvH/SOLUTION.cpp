
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> bicycleYard(vector<int>& position, vector<vector<int>>& terrain, vector<vector<int>>& obstacle) {
        vector<vector<int>> dd = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        vector<vector<int>> ans;
        
        set<tuple<int, int, int>> vi;
        vi.insert({ 1, position[0], position[1] });

        priority_queue<tuple<int, int, int>> pq;
        pq.push({ 1, position[0], position[1] });

        while (!pq.empty()) {
            auto [speed, x, y] = pq.top();
            pq.pop();

            for (auto& d : dd) {
                int dx = x + d[0];
                int dy = y + d[1];
                if (dx < 0 || dx >= terrain.size()) continue;
                if (dy < 0 || dy >= terrain[0].size()) continue;
                int s = speed + terrain[x][y] - terrain[dx][dy] - obstacle[dx][dy];
                if (s <= 0) continue;
                if (vi.find({s, dx, dy}) != vi.end()) continue;
                vi.insert({ s, dx, dy });
                pq.push({ s, dx, dy });
                if (s == 1) {
                    ans.push_back({ dx, dy });
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<int>& position, vector<vector<int>>& terrain, vector<vector<int>>& obstacle)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.bicycleYard(position, terrain, obstacle);
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
