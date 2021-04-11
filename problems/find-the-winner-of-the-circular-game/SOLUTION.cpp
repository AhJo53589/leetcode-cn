
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = (ans + k) % i;
        }
        return ans + 1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.findTheWinner(n, k);
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
