
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int dayOfYear(string date) {
        tm t;
        strptime(date.c_str(), "%Y-%m-%d", &t);
        return t.tm_yday + 1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string date)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.dayOfYear(date);
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
