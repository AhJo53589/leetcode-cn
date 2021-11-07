
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long countVowels(string word) {
        unordered_set<char> ci{ 'a', 'e', 'i', 'o', 'u' };

        long long ans = 0;
        for (int i = 0; i < word.size(); i++) {
            if (ci.find(word[i]) == ci.end()) continue;

            int left = i + 1;
            int right = (int)word.size() - i;
            ans += 1LL * left * right;
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
    return sln.countVowels(word);
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
