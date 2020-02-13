


//////////////////////////////////////////////////////////////////////////
int getSum(int a, int b)
{
	int c = a ^ b;
	unsigned int d = a & b;
#if 0
	// method one(faster but expend too much memory)
	return 0 != d ? getSum(c, d << 1) : c;
#else
	// method two(lower memory but slow)
	while (d)
	{
		d <<= 1;
		int t = c ^ d;
		d = c & d;
		c = t;
	}
	return c;
#endif
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int a, int b)
{
	return getSum(a,b);
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

