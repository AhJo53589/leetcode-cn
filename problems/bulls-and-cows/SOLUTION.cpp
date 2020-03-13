
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string getHint(string secret, string guess) 
    {
        int acnt = 0;
        int bcnt = 0;
        unordered_map<char, int> um;
        for (int i = 0; i < secret.size(); i++)
        {
            um[secret[i]]++;
            acnt += (secret[i] == guess[i]);
        }
        for (auto& c : guess)
        {
            bcnt += (um[c]-- > 0);
        }
        bcnt -= acnt;
        return to_string(acnt) + "A" + to_string(bcnt) + "B";
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string secret, string guess)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.getHint(secret, guess);
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
