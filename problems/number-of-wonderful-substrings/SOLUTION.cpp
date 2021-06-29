
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        for (int i = 0; i < word.size(); i++) {
            bitset<10> b;
            for (int j = i; j < word.size(); j++) {
                b[word[j] - 'a'].flip();
                ans += (b.count() < 2);
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
long _solution_run(string word)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.wonderfulSubstrings(word);
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
