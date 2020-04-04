
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canConstruct(string s, int k) 
    {
        if (s.size() < k) return false;
        vector<int> cnt(26, 0);
        for (auto c : s)
        {
            cnt[c - 'a']++;
        }

        int odd = 0;
        for (auto x : cnt)
        {
            odd += (x % 2 == 1);
        }

        return odd <= k;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    cout << s << "\t" << k << endl;
    Solution sln;
    return sln.canConstruct(s, k);
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
