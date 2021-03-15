
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> sz = { (int)matrix[0].size(), (int)matrix.size() };
        vector<int> ans(sz[0] * sz[1]);
        sz[1]--;

        vector<vector<int>> dd = { { 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 } };
        for (int idx = 0, d = 0, x = 0, y = -1; idx != ans.size(); d = (d + 1) % dd.size()) {
            for (int i = 0; i < sz[d % 2]; i++) {
                x += dd[d][0];
                y += dd[d][1];
                ans[idx++] = matrix[x][y];
            }
            sz[d % 2]--;
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& matrix)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.spiralOrder(matrix);
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
