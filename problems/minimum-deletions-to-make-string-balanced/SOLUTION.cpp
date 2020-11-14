
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> del_a(s.size(), 0);
        vector<int> del_b(s.size(), 0);
        del_b[0] = (s[0] == 'b');
        for (int i = 1; i < s.size(); i++) {
            del_b[i] = del_b[i - 1] + (s[i] == 'b');
        }
        del_a.back() = (s.back() == 'a');
        for (int i = s.size() - 2; i >= 0; i--) {
            del_a[i] = del_a[i + 1] + (s[i] == 'a');
        }

        int ans = INT_MAX;
        for (int i = 0; i < s.size() - 1; i++) {
            ans = min(ans, del_b[i] + del_a[i + 1]);
        }
        ans = min(ans, del_a.front());
        ans = min(ans, del_b.back());

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    cout << s << endl;
    Solution sln;
    return sln.minimumDeletions(s);
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
