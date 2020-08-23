
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            // Ä¨È¥×îÓÒ±ßµÄ 1
            n = n & (n - 1);
        }
        return n;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int m, int n)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.rangeBitwiseAnd(m, n);
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
