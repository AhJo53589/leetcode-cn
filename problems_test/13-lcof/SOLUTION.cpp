
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int dfs(int x, int y, int m, int n, int k, vector<vector<bool>>& vi, vector<vector<int>>& dd)
    {
        int ret = 1;
        for (auto& d : dd)
        {
            int tx = x + d[0];
            int ty = y + d[1];
            if (tx < 0 || tx >= m) continue;
            if (ty < 0 || ty >= n) continue;
            if (vi[tx][ty]) continue;
            vi[tx][ty] = true;

            int c = 0;
            for (int i = 0; i < 2; i++)
            {
                int t = (i == 0) ? tx : ty;
                while (t != 0)
                {
                    c += (t % 10);
                    t /= 10;
                }
            }
            if (c > k) continue;

            ret += dfs(tx, ty, m, n, k, vi, dd);
        }
        return ret;
    }

    int movingCount(int m, int n, int k)
    {
        vector<vector<int>> dd = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        vector<vector<bool>> vi(m, vector<bool>(n, false));
        vi[0][0] = true;
        return dfs(0, 0, m, n, k, vi, dd);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int m, int n, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.movingCount(m, n, k);
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
