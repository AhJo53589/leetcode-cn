
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int ans = 0;
        int st = 0;
        string stand = "aeiou";

        int i = 0;
        int j = 0;
        while (i < word.size()) {
            st = 0;
            j = i;
            if (word[i] != stand[st]) {
                i++;
                continue;
            }
            while (j < word.size()) {
                if (word[j] == stand[st]) {
                    if (st + 1 == stand.size()) {
                        ans = max(ans, j - i + 1);
                    }
                    j++;
                    continue;
                }
                if (st == stand.size() || word[j] != stand[st + 1]) {
                    i = j;
                    break;
                }
                st++;
                if (st + 1 == stand.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
            if (j == word.size()) break;
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
    return sln.longestBeautifulSubstring(word);
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
