
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        this->values = values;

        for (auto& edge : edges) {
            paths[edge[0]].push_back({ edge[1], edge[2] });
            paths[edge[1]].push_back({ edge[0], edge[2] });
        }

        dfs(0, 0, 0, maxTime);

        return ans;
    }

    void dfs(int nd, int curValue, int curTime, int maxTime) {
        int v = values[nd];
        values[nd] = 0;
        curValue += v;

        if (nd == 0) {
            ans = max(ans, curValue);
        }

        for (auto& p : paths[nd]) {
            int nt = curTime + p.second;
            if (nt > maxTime) continue;
            dfs(p.first, curValue, nt, maxTime);
        }

        curValue -= v;
        values[nd] = v;
    }

private:
    vector<int> values;
    unordered_map<int, vector<pair<int, int>>> paths;
    int ans;
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
