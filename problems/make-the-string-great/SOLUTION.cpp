
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string makeGood(string s) {
        int df = abs('A' - 'a');
        bool flag = true;
        while (flag) {
            if (s == "") break;
            flag = false;
            for (int i = 0; i < s.size() - 1; i++) {
                if (abs(s[i] - s[i + 1]) == df) {
                    s.erase(i, 2);
                    flag = true;
                    break;
                }
            }
        }
        return s;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.makeGood(s);
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
