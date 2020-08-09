
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    char findKthBit(int n, int k) {
        if (k == 1) return '0';
        string s = "0";
        while (--n > 0) {
            string t = s;
            s += "1";
            for (int i = t.size() - 1; i >= 0; i--) {
                s += (t[i] == '0') ? '1' : '0';
            }
        }
        return s[k - 1];
    }
};

//////////////////////////////////////////////////////////////////////////
char _solution_run(int n, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << n << ", " << k << endl;
    Solution sln;
    return sln.findKthBit(n, k);
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
