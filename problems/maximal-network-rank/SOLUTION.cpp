
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> cnt;
        for (int i = 0; i < n; i++) {
            cnt.push_back({ 0, i });
        }

        set<pair<int, int>> sp;
        for (auto& rd : roads) {
            cnt[rd[0]][0]++;
            cnt[rd[1]][0]++;
            sp.insert({ rd[0], rd[1] });
            sp.insert({ rd[1], rd[0] });
        }

        int ans = 0;
        sort(cnt.rbegin(), cnt.rend());
        for (int i = 1; i < cnt.size(); i++) {
            int temp = cnt[0][0] + cnt[i][0] - (sp.count({ cnt[0][1], cnt[i][1] }));
            ans = max(ans, temp);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& roads)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maximalNetworkRank(n, roads);
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
