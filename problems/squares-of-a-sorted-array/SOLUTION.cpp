
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        for (int i = 0, j = A.size() - 1; i <= j; i++) {
            while (i < j && abs(A[i]) < abs(A[j])) {
                ans.push_back(A[j] * A[j]);
                j--;
            }
            ans.push_back(A[i] * A[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& A)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.sortedSquares(A);
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
