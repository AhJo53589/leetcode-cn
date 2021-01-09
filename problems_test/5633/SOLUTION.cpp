
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int t = 0;
        int x = 0;
        while (x + 7 < n) {
            ans += 28 + 7 * (t++);
            x += 7;
        }
        while (x++ < n) {
            ans += (++t);
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

    Solution sln;
    return sln.totalMoney(n);
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
