
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> conn_idx(n, vector<int>());
        for (int i = 0; i < connections.size(); i++) {
            conn_idx[connections[i][0]].push_back(i);
            conn_idx[connections[i][1]].push_back(i);
        }

        vector<bool> vi(connections.size(), false);
        int ans = 0;

        queue<int> que;
        que.push(0);

        while (!que.empty()) {
            auto q = que.front();
            que.pop();

            for (auto idx : conn_idx[q]) {
                if (vi[idx]) continue;
                vi[idx] = true;

                int a = connections[idx][0];
                int b = connections[idx][1];

                ans += (a == q);
                a = (a == q) ? b : a;
                que.push(a);
            }
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& connections)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minReorder(n, connections);
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
