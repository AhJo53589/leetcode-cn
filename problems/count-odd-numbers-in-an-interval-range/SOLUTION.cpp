
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countOdds(int low, int high) {
		int ans = 0;
		ans += (low % 2);
		low += (low % 2);
		high += (high % 2);
		ans += (high - low) / 2;
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int low, int high)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.countOdds(low, high);
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
