
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (auto c : n) {
            ans = max(ans, (int)(c - '0'));
        }
        return (n == "0") ? 1 : ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minPartitions(n);
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
