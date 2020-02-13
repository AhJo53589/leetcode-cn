
//int reverse(int x)
//{
//	long result = 0;
//	while (x != 0) {
//		result = result * 10 + x % 10;
//		x /= 10;
//	}
//	if (result > 2147483647 || result < -2147483648) {
//		return 0;
//	}
//	return (int)result;
//}


//////////////////////////////////////////////////////////////////////////
int reverse(int x)
{
	int result = 0;
	while (x != 0)
	{
		if (result > INT_MAX / 10 || result < INT_MIN / 10)
		{
			return 0;
		}
		result = result * 10 + x % 10;
		x = x / 10;
	}
	return result;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(int x)
{
	return reverse(x);
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

