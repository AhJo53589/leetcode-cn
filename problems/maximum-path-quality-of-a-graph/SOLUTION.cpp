
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        vector<vector<int>> path(values.size(), vector<int>(values.size(), 0));
        for (auto& edge : edges) {
            path[edge[0]][edge[1]] = edge[2];
            path[edge[1]][edge[0]] = edge[2];
        }

        int ans = values[0];

        queue<tuple<int, int, bitset<1001>>> pq;
        bitset<1001> b(1);
        pq.push({ 0, 0, b });
        while (!pq.empty()) {
            auto [t, nd, val] = pq.front();
            pq.pop();

            for (int i = 0; i < path[nd].size(); i++) {
                if (path[nd][i] == 0) continue;
                auto cv = val[i];
                cv.set(i, 1);
                int ct = t + path[nd][i];
                if (ct > maxTime) continue;

                pq.push({ ct, i, cv });
                if (i == 0) {
                    ans = max(ans, getVal(values, cv));
                }
            }
        }
        return ans;
    }

    int getVal(vector<int>& values, bitset<1000> cv) {
        int val = 0;
        for (int i = 0; i < values.size(); i++) {
            val += cv[i] * values[i];
        }
        return val;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& values, vector<vector<int>>& edges, int maxTime)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maximalPathQuality(values, edges, maxTime);
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
