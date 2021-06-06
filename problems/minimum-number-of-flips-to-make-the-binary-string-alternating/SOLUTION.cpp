
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minFlips(string s) {
        int len = s.size();
        string target = "01";

        int cnt = 0;
        for (int i = 0; i < len; i++) {
            cnt += (s[i] != target[i % 2]);
        }

        s += s;
        int ans = min({ cnt, len - cnt });
        for (int i = 0; i < len; i++) {
            cnt -= (s[i] != target[i % 2]);
            cnt += (s[i + len] != target[(i + len) % 2]);
            ans = min({ ans, cnt, len - cnt });
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    if (s.size() < 20) cout << s << endl;

    Solution sln;
    return sln.minFlips(s);
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
