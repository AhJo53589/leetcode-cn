
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        vector<int> sz = { n, n - 1 };
        vector<vector<int>> dd = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        
        for (int val = 1, d = 0, x = 0, y = -1; val <= n * n; d = (d + 1) % dd.size()) {
            for (int i = 0; i < sz[d % 2]; i++) {
                x += dd[d][0];
                y += dd[d][1];
                ans[x][y] = val++;
            }
            sz[d % 2]--;
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(int n)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.generateMatrix(n);
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
