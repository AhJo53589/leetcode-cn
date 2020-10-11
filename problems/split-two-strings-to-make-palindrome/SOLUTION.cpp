
//////////////////////////////////////////////////////////////////////////
//class Solution {
//public:
//    bool checkPalindromeFormation(string a, string b) {
//        int l = a.size() / 2 - 1;
//        int r = a.size() / 2 + (a.size() % 2 == 1);
//
//        vector<bool> flag(2, true);
//        while (l >= 0 && r < a.size()) {
//            if (flag[0] && a[l] != a[r]) {
//                flag[0] = false;
//            }
//            if (flag[1] && b[l] != b[r]) {
//                flag[1] = false;
//            }
//            if (none_of(flag.begin(), flag.end(), [](bool x) { return x; })) break;
//            l--;
//            r++;
//        }
//
//        flag = vector<bool>(2, true);
//        while (l >= 0 && r < a.size()) {
//            if (flag[0] && a[l] != b[r]) {
//                flag[0] = false;
//            }
//            if (flag[1] && b[l] != a[r]) {
//                flag[1] = false;
//            }
//            if (none_of(flag.begin(), flag.end(), [](bool x) { return x; })) break;
//            l--;
//            r++;
//        }
//
//        return l == -1;
//    }
//};

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int left = a.size() / 2 - 1;
        left = min(check(a, a, left), check(b, b, left));
        left = min(check(a, b, left), check(b, a, left));
        return left == -1;
    }

    int check(string str_l, string str_r, int left) {
        int right = str_l.size() - 1 - left;
        while (left >= 0 && right < str_l.size()) {
            if (str_l[left] != str_r[right]) break;
            left--;
            right++;
        }
        return left;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string a, string b)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << a << endl << b << endl;
    Solution sln;
    return sln.checkPalindromeFormation(a, b);
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
