
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numberOfSteps (int num)
	{
		int ans = 0;
		while (num != 0)
		{
			num = (num % 2 == 0) ? num / 2 : num - 1;
			ans++;
		}
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int num)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.numberOfSteps(num);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
