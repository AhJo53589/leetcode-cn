
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		int ans = 0;
		for (int i = 0; i < startTime.size(); i++) {
			ans += (queryTime >= startTime[i] && queryTime <= endTime[i]);
		}
		return ans;
	}
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& startTime, vector<int>& endTime, int queryTime)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.busyStudent(startTime, endTime, queryTime);
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
