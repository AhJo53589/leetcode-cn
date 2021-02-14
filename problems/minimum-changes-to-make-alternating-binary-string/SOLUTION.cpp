
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minOperations(string s) {
        return min(count(s, '0'), count(s, '1'));
    }

    int count(string s, char cur) {
        int ans = 0;
        for (auto c : s) {
            ans += (c != cur);
            cur = (cur == '0') ? '1' : '0';
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
    cout << s << endl;

    Solution sln;
    return sln.minOperations(s);
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
