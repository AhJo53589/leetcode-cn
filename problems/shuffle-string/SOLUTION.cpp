
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans(s.size(), '0');
        for (int i = 0; i < indices.size(); i++) {
            ans[indices[i]] = s[i];
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s, vector<int>& indices)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.restoreString(s, indices);
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
