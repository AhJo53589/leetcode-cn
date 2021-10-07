
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string t;
        int ans = 0;
        while (ss >> t) {
            ans++;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.countSegments(s);
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
