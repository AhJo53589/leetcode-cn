
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int state = 0;
        for (auto& c : num) {
            int n = c - '0';
            if (state == 0 and n >= change[n]) continue;
            if (state == 1 and n > change[n]) break;
            c = (char)('0' + change[n]);
            state = 1;
        }
        return num;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string num, vector<int>& change)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maximumNumber(num, change);
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
