
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {
        unordered_map<char, int> cc = { {'>', 0}, {'v', 1}, {'<', 2}, {'^', 3} };
        vector<vector<int>> dd = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

        vector<vector<int>> vi(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({ 0, start[0], start[1] });
        vi[start[0]][start[1]] = 0;

        while (!pq.empty()) {
            auto q = pq.top();
            pq.pop();

            int x = q[1];
            int y = q[2];
            int to = cc[matrix[x][y]];
            for (int i = 0; i < dd.size(); i++) {
                int dx = x + dd[i][0];
                int dy = y + dd[i][1];
                if (dx < 0 || dx >= vi.size() || dy < 0 || dy >= vi[0].size()) continue;
                int change = q[0] + (to != i);
                if (vi[dx][dy] > change) {
                    vi[dx][dy] = change;
                    pq.push({ change, dx, dy });
                }
            }
        }

        return vi[end[0]][end[1]];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& matrix, vector<int>& start, vector<int>& end)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.conveyorBelt(matrix, start, end);
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
