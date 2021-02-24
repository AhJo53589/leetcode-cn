
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A[0].size();
        for (int i = 0; i < A.size(); i++) {
            for (int x = 0; x < n / 2; x++) {
                int y = n - x - 1;
                swap(A[i][x], A[i][y]);
                A[i][x] ^= 1;
                A[i][y] ^= 1;
            }
            if (n % 2 == 0) continue;
            A[i][n / 2] ^= 1;

        }
        return A;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& A)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.flipAndInvertImage(A);
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
