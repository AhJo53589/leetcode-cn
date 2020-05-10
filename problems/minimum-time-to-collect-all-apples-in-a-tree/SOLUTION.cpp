
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> ft(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            ft[edges[i][0]].push_back(edges[i][1]);
        }

        int ans = 0;
        minTime(0, ft, hasApple, ans);
        return ans;
    }

    bool minTime(int from, vector<vector<int>>& ft, vector<bool>& hasApple, int& ans) {
        bool ha = hasApple[from];
        for (auto& to : ft[from]) {
            if (minTime(to, ft, hasApple, ans)) {
                ha = true;
            }
        }
        ans += (ha && from != 0) ? 2 : 0;
        return ha;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& edges, vector<bool>& hasApple)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minTime(n, edges, hasApple);
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
