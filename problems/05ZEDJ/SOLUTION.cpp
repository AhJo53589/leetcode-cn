
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> volunteerDeployment(vector<int>& finalCnt, long long totalNum, vector<vector<int>>& edges, vector<vector<int>>& plans) {
        vector<vector<int>> paths(finalCnt.size() + 1);
        for (auto d : edges) {
            paths[d[0]].push_back(d[1]);
            paths[d[1]].push_back(d[0]);
        }

        vector<pair<int, long long>> t(paths.size());
        t[0] = { 1, 0 };
        for (int i = 0; i < finalCnt.size(); i++) {
            t[i + 1] = { 0, finalCnt[i] };
        }

        for (int i = (int)plans.size() - 1; ~i; i--) {
            int num = plans[i][0];
            int idx = plans[i][1];
            auto&[ca, cb] = t[idx];

            if (num == 1) {
                ca *= 2;
                cb *= 2;
            }
            else {
                int f = (num == 2) ? -1 : 1;
                for (auto n : paths[idx]) {
                    auto&[a, b] = t[n];
                    a += ca * f;
                    b += cb * f;
                }
            }
        }

        int sx = 0;
        for (auto&[a, b] : t) {
            sx += a;
            totalNum -= b;
        }
        int x = totalNum / sx;

        vector<int> ans(t.size());
        for (int i = 0; i < t.size(); i++) {
            auto[a, b] = t[i];
            ans[i] = a * x + b;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& finalCnt, long long totalNum, vector<vector<int>>& edges, vector<vector<int>>& plans)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.volunteerDeployment(finalCnt, totalNum, edges, plans);
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
