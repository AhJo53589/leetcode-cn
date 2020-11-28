
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        for (int i = 0; i < sequence.size(); i++) {
            int k = 0;
            for (int j = i; j < sequence.size(); j++) {
                if (sequence[j] != word[(j - i) % word.size()]) break;
                if ((j - i + 1) % word.size() == 0) {
                    ans = max(ans, ++k);
                }
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string sequence, string word)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxRepeating(sequence, word);
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
