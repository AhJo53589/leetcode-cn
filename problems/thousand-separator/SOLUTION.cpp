
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0) return "0";
        string ans;
        int k = 0;
        while (n > 0) {
            if ((k++) % 3 == 0) {
                ans += ".";
            }
            ans += '0' + (n % 10);
            n /= 10;
        }
        reverse(ans.begin(), ans.end());
        ans.pop_back();
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.thousandSeparator(n);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
