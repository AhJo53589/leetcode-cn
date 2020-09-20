
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> word;
        int space_cnt = 0;
        string temp;
        for (int i = 0; i < text.size(); i++) {
            space_cnt += isspace(text[i]) != 0;
            if (isalpha(text[i])) {
                temp += text[i];
            }
            if (isspace(text[i]) && temp != "") {
                word.push_back(temp);
                temp = "";
            }
        }
        if (temp != "") {
            word.push_back(temp);
        }

        string ans;
        if (word.size() == 1) {
            ans = word[0];
            for (int j = 0; j < space_cnt; j++) {
                ans += " ";
            }
            return ans;
        }

        for (int i = 0; i < word.size(); i++) {
            ans += word[i];
            if (i == word.size() - 1) continue;
            for (int j = 0; j < space_cnt / (word.size() - 1); j++) {
                ans += " ";
            }
        }
        for (int j = 0; j < space_cnt % (word.size() - 1); j++) {
            ans += " ";
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string text)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    cout << text << endl;
    Solution sln;
    return sln.reorderSpaces(text);
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
