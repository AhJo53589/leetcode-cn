
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < words.size()) {
            if ((int)s.size() - i < words[j].size()) return false;
            for (int k = 0; k < words[j].size(); k++) {
                if (s[i + k] != words[j][k]) return false;
            }
            i += words[j].size();
            j++;
            if (i == s.size()) return true;
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s, vector<string>& words)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.isPrefixString(s, words);
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
