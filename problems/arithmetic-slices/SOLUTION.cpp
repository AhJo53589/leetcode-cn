
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0;
        int start = 0;
        while (start + 2 < A.size()) {
            int i = 2;
            while (start + i < A.size()) {
                if (A[start + 1] - A[start] == A[start + i] - A[start + i - 1]) {
                    i++;
                    continue;
                }
                break;
            }
            start += i - 1;
            ans += (i > 2) ? (1 + (i - 2)) * (i - 2) / 2 : 0;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& A)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.numberOfArithmeticSlices(A);
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
