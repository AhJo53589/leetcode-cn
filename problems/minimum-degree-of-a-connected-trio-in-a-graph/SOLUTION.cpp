
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int ans = INT_MAX;

        vector<vector<bool>> vi(n + 1, vector<bool>(n + 1, false));
        vector<int> cnt(n + 1, 0);
        for (auto& e : edges) {
            vi[e[0]][e[1]] = true;
            vi[e[1]][e[0]] = true;
            cnt[e[0]]++;
            cnt[e[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (!vi[i][j]) continue;
                for (int k = j + 1; k <= n; k++) {
                    ans = (vi[i][k] && vi[j][k]) ? min(ans, cnt[i] + cnt[j] + cnt[k] - 6) : ans;
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& edges)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    //cout << n << endl;
    //printVectorVectorT(edges);

    Solution sln;
    return sln.minTrioDegree(n, edges);
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
