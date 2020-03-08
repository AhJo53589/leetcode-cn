
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) 
    {
        vector<vector<int>> path(n + 1);
        for (auto& e : edges)
        {
            path[e[0]].push_back(e[1]);
            path[e[1]].push_back(e[0]);
        }

        vector<vector<double>> f(111, vector<double>(n + 1));
        auto& ff = f;

        function<void(int, int, int)> dfs = [&](int id, int tt, int preId)
        {
            int sons = 0;
            for (auto y : path[id])
            {
                if (y == preId) continue;
                sons++;
            }
            for (auto y : path[id])
            {
                if (y == preId) continue;
                f[tt + 1][y] = f[tt][id] / sons;
                dfs(y, tt + 1, id);
            }
            if (sons == 0)
            {
                for (int i = tt + 1; i <= t; ++i)
                {
                    f[i][id] = f[tt][id];
                }
            }
        };

        f[0][1] = 1;
        dfs(1, 0, 0);

        return f[t][target];
    }
};

//////////////////////////////////////////////////////////////////////////
double _solution_run(int n, vector<vector<int>>& edges, int t, int target)
{
    int caseNo = -1;
    static int caseCnt = 0;
	if (caseNo != -1 && caseCnt++ != caseNo)
	{
		cout << "\t\t\t\t\t\t\t\t\t\t## SKIP ##" << endl;
		return {};
	}

	Solution sln;
	return sln.frogPosition(n, edges, t, target);
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
