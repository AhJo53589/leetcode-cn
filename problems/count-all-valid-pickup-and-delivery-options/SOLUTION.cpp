
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countOrders(int n)
	{
		long long res = 1;
		long long md = 1e9 + 7;
		for (int i = 1; i <= n; i++)
		{
			res = res * i;
			res = res * (2 * i - 1);
			res %= md;
		}
		return res;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.countOrders(n);
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
