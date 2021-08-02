
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int getLucky(string s, int k) {
        string num;
        for (auto c : s) {
            num += to_string(c - 'a' + 1);
        }
        
        int ans = 0;
        while (k-- > 0) {
            ans = 0;
            for (auto c : num) {
                ans += (c - '0');
            }
            num = to_string(ans);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.getLucky(s, k);
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
