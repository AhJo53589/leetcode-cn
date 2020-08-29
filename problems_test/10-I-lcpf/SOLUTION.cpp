
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int f2 = 0, f1 = 1;
        int res;
        for (int i = 2; i <= n; i++) {
            res = (f2 + f1) % 1000000007;
            f2 = f1; f1 = res;
        }
        return res;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.fib(n);
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
