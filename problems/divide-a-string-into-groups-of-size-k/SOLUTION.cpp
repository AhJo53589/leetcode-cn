
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string sub;
        int i = 0;
        for (auto& c : s) {
            sub += c;
            i = (i + 1) % k;
            if (i == 0) {
                ans.push_back(sub);
                sub = "";
            }
        }
        while (i != 0) {
            sub += fill;
            i = (i + 1) % k;
        }
        if (sub != "") {
            ans.push_back(sub);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(string s, int k, char fill)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.divideString(s, k, fill);
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
