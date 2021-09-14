
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string reversePrefix(string word, char ch) {
        bool find = false;
        string ans;
        for (auto c : word) {
            if (!find) {
                ans += c;
                if (c == ch) {
                    find = true;
                    reverse(ans.begin(), ans.end());
                }
            }
            else {
                ans += c;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string word, char ch)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.reversePrefix(word, ch);
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
