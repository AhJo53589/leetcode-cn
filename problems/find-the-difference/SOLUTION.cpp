
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        unordered_map<char, int> cnt;
        for (auto c : s)
        {
            cnt[c]++;
        }
        for (auto c : t)
        {
            cnt[c]--;
            if (cnt[c] < 0) return c;
        }
        return {};
    }
};

//////////////////////////////////////////////////////////////////////////
char _solution_run(string s, string t)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.findTheDifference(s, t);
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
