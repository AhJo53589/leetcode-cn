
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isThree(int n) {
        int ans = 0;
        for (int i = 2; i < n; i++) {
            ans += (n % i == 0);
        }
        return ans == 1;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.isThree(n);
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
