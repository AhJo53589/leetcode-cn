
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxDiff(int num) {
        string n = to_string(num);
        return getA(n) - getB(n);
    }

    int getA(string n) {
        char t = ' ';
        for (int i = 0; i < n.size(); i++) {
            if (n[i] == '9') continue;
            t = (t == ' ') ? n[i] : t;
            if (n[i] != t) continue;
            n[i] = '9';
        }
        return stoi(n);
    }

    int getB(string n) {
        char t = ' ';
        char exclue = ' ';
        char change = ' ';
        for (int i = 0; i < n.size(); i++) {
            if (i == 0) {
                if (n[i] == '1') {
                    exclue = '1';
                    continue;
                }
                t = n[i];
                change = '1';
                n[i] = change;
                continue;
            }
            if (n[i] == '0' || n[i] == exclue) continue;
            t = (t == ' ') ? n[i] : t;
            if (n[i] != t) continue;
            change = (change == ' ') ? '0' : change;
            n[i] = change;
        }
        return stoi(n);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int num)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << num << endl;
    Solution sln;
    return sln.maxDiff(num);
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
