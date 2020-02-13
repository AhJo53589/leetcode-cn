
//double myPow(double x, int n)	// 12ms
//{
//	double res = 1.0;
//	for (int i = n; i != 0; i /= 2) {
//		if (i % 2 != 0) {
//			res *= x;
//		}
//		x *= x;
//	}
//	return  n < 0 ? 1 / res : res;
//}

//////////////////////////////////////////////////////////////////////////
double myPow(double x, int n)	// 4ms
{
	switch (n)
	{
	case -1:
		return 1 / x;
	case 0:
		return 1.0;
	case 1:
		return x;
	case 2:
		return x * x;
	}

	return myPow(myPow(x, 2), n / 2) * myPow(x, n % 2);
}

//////////////////////////////////////////////////////////////////////////
double _solution_run(double x, int n)
{
	return myPow(x,n);
}

//#define USE_SOLUTION_CUSTOM
//double _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

