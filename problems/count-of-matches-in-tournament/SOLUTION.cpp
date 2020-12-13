
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while (n > 0) {
            ans += (n % 2);
            n /= 2;
            ans += n;
        }
        return ans - 1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.numberOfMatches(n);
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
