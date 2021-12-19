
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (j < spaces.size() && i == spaces[j]) {
                ans += " ";
                j++;
            }
            ans += s[i];
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s, vector<int>& spaces)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.addSpaces(s, spaces);
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
