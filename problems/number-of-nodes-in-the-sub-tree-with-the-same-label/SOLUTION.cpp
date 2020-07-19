
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n, 0);
        vector<vector<int>> path(n);
        vi = vector<bool>(n, false);
        for (int i = 0; i < edges.size(); i++) {
            path[edges[i][0]].push_back(edges[i][1]);
            path[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(path, labels, 0, ans);
        return ans;
    }

    vector<int> dfs(vector<vector<int>>& path, string& labels, int idx, vector<int>& ans) {
        vi[idx] = true;
        vector<int> cnt(26, 0);
        cnt[labels[idx] - 'a']++;

        for (auto i : path[idx]) {
            if (vi[i]) continue;
            auto t = dfs(path, labels, i, ans);
            for (int j = 0; j < cnt.size(); j++) {
                cnt[j] += t[j];
            }
        }
        ans[idx] = cnt[labels[idx] - 'a'];
        return cnt;
    }

private:
    vector<bool> vi;
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int n, vector<vector<int>>& edges, string labels)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.countSubTrees(n, edges, labels);
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
