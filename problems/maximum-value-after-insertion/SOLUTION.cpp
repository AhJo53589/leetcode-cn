
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string maxValue(string n, int x) {
        int flag = (n[0] == '-') ? -1 : 1;
        int i = (flag == -1) ? 1 : 0;
        for (; i < n.size(); i++) {
            if ((n[i] - '0') * flag < x * flag) break;
        }
        n.insert(i, 1, '0' + x);
        return n;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string n, int x)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << n << endl << x << endl;

    Solution sln;
    return sln.maxValue(n, x);
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
