
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans = -1;
        int i = 0;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            if (word.size() >= searchWord.size()) {
                bool flag = true;
                for (int j = 0; j < searchWord.size(); j++) {
                    if (word[j] != searchWord[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans = i;
                    break;
                }
            }
            i++;
        }
        return ans == -1 ? ans : ans + 1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string sentence, string searchWord)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << sentence << endl;
    cout << searchWord << endl;
    Solution sln;
    return sln.isPrefixOfWord(sentence, searchWord);
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
