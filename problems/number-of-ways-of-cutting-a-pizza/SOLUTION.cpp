
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        vector<vector<vector<int>>> cache(11, vector<vector<int>>(51, vector<int>(51, -1)));
        return dfs(pizza, k, 0, 0, cache);
    }

    int dfs(vector<string>& pizza, int k, int r, int c, vector<vector<vector<int>>>& cache) {
        if (cache[k][r][c] != -1) return cache[k][r][c];

        int ans = 0;

        if (k == 0) {
            ans = (int)getApple(pizza, r, pizza.size(), c, pizza[0].size());
            cache[k][r][c] = ans;
            cout << "[k == 0] " << r << " " << c << " = " << ans << endl;
            return ans;
        }

        bool ha1 = false;
        for (int i = r + 1; i < pizza.size(); i++) {
            if (!ha1 && !getApple(pizza, r, i, c, pizza[0].size())) continue;
            ha1 = true;
            ans += dfs(pizza, k - 1, i, c, cache);
        }

        bool ha2 = false;
        for (int j = c + 1; j < pizza[0].size(); j++) {
            if (!ha2 && !getApple(pizza, r, pizza.size(), c, j)) continue;
            ha2 = true;
            ans += dfs(pizza, k - 1, r, j, cache);
        }

        cache[k][r][c] = ans;
        return ans;
    }

    bool getApple(vector<string>& pizza, int r1, int r2, int c1, int c2) {
        for (int i = r1; i < r2; i++) {
            for (int j = c1; j < c2; j++) {
                if (pizza[i][j] == 'A') return true;
            }
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& pizza, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.ways(pizza, k);
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
