
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_map<char, int> ci;
        ci['a'] = 0;
        ci['e'] = 1;
        ci['i'] = 2;
        ci['o'] = 3;
        ci['u'] = 4;

        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            if (ci.find(word[i]) == ci.end()) continue;
            bitset<5> vb;
            for (int j = i; j < word.size(); j++) {
                if (ci.find(word[j]) == ci.end()) break;
                vb.set(ci[word[j]], 1);
                ans += vb.count() == 5;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string word)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.countVowelSubstrings(word);
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
