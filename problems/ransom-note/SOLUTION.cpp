
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int> cnt;
        for (auto c : magazine)
        {
            cnt[c]++;
        }
        for (auto c : ransomNote)
        {
            cnt[c]--;
            if (cnt[c] < 0) return false;
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string ransomNote, string magazine)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.canConstruct(ransomNote, magazine);
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
