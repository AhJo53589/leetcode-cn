
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return trans(firstWord) + trans(secondWord) == trans(targetWord);
    }

    int trans(string s) {
        int ans = 0;
        for (auto c : s) {
            ans *= 10;
            ans += c - 'a';
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string firstWord, string secondWord, string targetWord)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.isSumEqual(firstWord, secondWord, targetWord);
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
