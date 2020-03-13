
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string convertToTitle(int n) 
    {
        string ans = "";
        while (n > 0)
        {
            //n -= 1;
            ans.push_back('A' + ((n - 1) % 26));
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    cout << n << endl;
    Solution sln;
    return sln.convertToTitle(n);
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
