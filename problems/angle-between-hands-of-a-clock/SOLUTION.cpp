
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    double angleClock(int hour, int minutes) 
	{
		double c1 = 30 * hour + 0.5 * minutes;
		double c2 = 6 * minutes;
		double ans = abs(c1 - c2);
		return ans < 180.0 ? ans : 360 - ans;
    }
};

//////////////////////////////////////////////////////////////////////////
double _solution_run(int hour, int minutes)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.angleClock(hour, minutes);
}

//#define USE_SOLUTION_CUSTOM
//double _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
