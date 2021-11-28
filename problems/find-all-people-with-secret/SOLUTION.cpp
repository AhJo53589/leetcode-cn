
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> known(n);
        known[0] = true;
        known[firstPerson] = true;

        int maxT = 0;
        for (auto& meeting : meetings) {
            maxT = max(maxT, meeting[2]);
        }
        vector<vector<pair<int, int>>> time(maxT + 1);
        for (auto& meeting : meetings) {
            time[meeting[2]].emplace_back(meeting[0], meeting[1]);
        }

        vector<vector<int>> adj(n);
        for (int i = 1; i <= maxT; ++i) {
            if (time[i].empty()) continue;

            unordered_set<int> vis;
            queue<int> que;
            for (auto& [u, v] : time[i]) {
                adj[u].emplace_back(v);
                adj[v].emplace_back(u);
                if (known[u] && !vis.count(u)) {
                    vis.insert(u);
                    que.push(u);
                }
                if (known[v] && !vis.count(v)) {
                    vis.insert(v);
                    que.push(v);
                }
            }

            while (!que.empty()) {
                int q = que.front();
                que.pop();
                for (int v : adj[q]) {
                    if (!vis.count(v)) {
                        known[v] = true;
                        vis.insert(v);
                        que.push(v);
                    }
                }
            }

            for (auto& [u, v] : time[i]) {
                adj[u].clear();
                adj[v].clear();
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (known[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};


//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int n, vector<vector<int>>& meetings, int firstPerson)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.findAllPeople(n, meetings, firstPerson);
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
