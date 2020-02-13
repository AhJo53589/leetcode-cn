


//////////////////////////////////////////////////////////////////////////
int climbStairs(int n)
{
	if (n <= 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	int s1 = 1;
	int s2 = 2;
	int ret = 0;
	for (int i = 3; i <= n; i++)
	{
		ret = s1 + s2;
		s1 = s2;
		s2 = ret;
	}
	return ret;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	return climbStairs(n);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

