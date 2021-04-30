
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isNumber(string s) {
        int st = 0;
        for (auto c : s) {
            EType t = getType(c);
            if (t == E_Err) return false;
            switch (st) {
            case 0:
                st = t == E_E ? -1 : st;
                st = t == E_Op ? 1 : st;
                st = t == E_Dot ? 3 : st;
                st = t == E_Digit ? 2 : st;
                break;
            case 1:
                st = t == E_E ? -1 : st;
                st = t == E_Op ? -1 : st;
                st = t == E_Dot ? 3 : st;
                st = t == E_Digit ? 2 : st;
                break;
            case 2:
                st = t == E_E ? 5 : st;
                st = t == E_Op ? -1 : st;
                st = t == E_Dot ? 4 : st;
                st = t == E_Digit ? 2 : st;
                break;
            case 3:
                st = t == E_E ? -1 : st;
                st = t == E_Op ? -1 : st;
                st = t == E_Dot ? -1 : st;
                st = t == E_Digit ? 4 : st;
                break;
            case 4:
                st = t == E_E ? 5 : st;
                st = t == E_Op ? -1 : st;
                st = t == E_Dot ? -1 : st;
                st = t == E_Digit ? 4 : st;
                break;
            case 5:
                st = t == E_E ? -1 : st;
                st = t == E_Op ? 6 : st;
                st = t == E_Dot ? -1 : st;
                st = t == E_Digit ? 7 : st;
                break;
            case 6:
            case 7:
                st = t == E_E ? -1 : st;
                st = t == E_Op ? -1 : st;
                st = t == E_Dot ? -1 : st;
                st = t == E_Digit ? 7 : st;
                break;
            }
            if (st == -1) return false;
        }

        return st == 2 || st == 4 || st == 7;
    }

    enum EType {
        E_Err = 0,
        E_E = 1,
        E_Op = 2,
        E_Dot = 3,
        E_Digit = 4
    };

    EType getType(char c) {
        if (c == 'e' || c == 'E') return E_E;
        if (c == '+' || c == '-') return E_Op;
        if (c == '.') return E_Dot;
        if (isdigit(c)) return E_Digit;
        return E_Err;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.isNumber(s);
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
