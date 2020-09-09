
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (i == j || i + j == mat.size() - 1) {
                    ans += mat[i][j];
                }
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& mat)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.diagonalSum(mat);
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
