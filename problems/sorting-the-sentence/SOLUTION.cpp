
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string sortSentence(string s) {
        vector<string> str(9);
        stringstream ss(s);
        string temp;
        int n = 0;
        while (ss >> temp) {
            int idx = temp.back() - '0';
            n = max(n, idx);
            temp.pop_back();
            str[idx - 1] = temp;
        }

        string ans;
        for (int i = 0; i < n; i++) {
            ans += str[i];
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.sortSentence(s);
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
