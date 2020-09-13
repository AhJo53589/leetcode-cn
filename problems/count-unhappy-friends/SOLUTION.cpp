
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<bool> happy(n, true);

        vector<int> frd(n);
        for (auto p : pairs) {
            frd[p[0]] = p[1];
            frd[p[1]] = p[0];
        }

        vector<vector<int>> pre(n, vector<int>(n));
        for (int x = 0; x < preferences.size(); x++) {
            for (int j = 0; j < preferences[x].size(); j++) {
                pre[x][preferences[x][j]] = j;
            }
        }

        for (int x = 0; x < n; x++) {
            for (auto u : preferences[x]) {
                if (u == frd[x]) break;
                if (pre[u][x] < pre[u][frd[u]]) {
                    happy[x] = false;
                    happy[u] = false;
                }
            }
        }

        int ans = 0;
        for (auto h : happy) {
            ans += (!h);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.unhappyFriends(n, preferences, pairs);
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
