
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int tribonacci(int n) {
        vector<int> T = {0, 1, 1};
        for (int i = 3; i <= n; i++) {
            T.push_back(T[i - 3] + T[i - 2] + T[i - 1]);
        }
        return T[n];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.tribonacci(n);
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
