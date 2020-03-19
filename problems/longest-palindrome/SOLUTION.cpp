
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> cnt;
        for (auto c : s)
        {
            cnt[c]++;
        }
        int ans = 0;
        int odd = 0;
        for (auto& p : cnt)
        {
            odd = (odd == 1 || p.second % 2 == 1);
            ans += (p.second / 2 * 2);
        }
        return ans + odd;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.longestPalindrome(s);
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
