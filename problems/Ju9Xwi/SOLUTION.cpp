
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int leastMinutes(int n) {
        int ans = INT_MAX;
        int x = 0;
        int t = 1;
        while (t <= n) {
            ans = min(ans, x + n / t + (n % t != 0));
            x++;
            t *= 2;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << n << endl;
    Solution sln;
    return sln.leastMinutes(n);
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
