
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        unordered_map<int, int> e_cnt;
        vector<int> p_cnt(n + 1, 0);
        for (auto& edge : edges) {
            int u = min(edge[0], edge[1]);
            int v = max(edge[0], edge[1]);
            p_cnt[u]++;
            p_cnt[v]++;
            e_cnt[u * (n + 1) + v]++;
        }

        vector<int> vc((n * (n - 1) / 2), 0);
        int idx = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                vc[idx++] = p_cnt[i] + p_cnt[j] - e_cnt[i * (n + 1) + j];
            }
        }
        sort(vc.begin(), vc.end());

        vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            auto it = lower_bound(vc.begin(), vc.end(), queries[i] + 1);
            ans[i] = vc.end() - it;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int n, vector<vector<int>>& edges, vector<int>& queries)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.countPairs(n, edges, queries);
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
