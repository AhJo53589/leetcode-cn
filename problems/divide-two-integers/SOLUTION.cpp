


//////////////////////////////////////////////////////////////////////////
int divide(int dividend, int divisor)
{
	if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
	int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
	long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
	while (m >= n)
	{
		long long t = n, p = 1;
		while (m >= (t << 1))
		{
			t <<= 1;
			p <<= 1;
		}
		m -= t;
		res += p;
	}
	return sign == 1 ? res : -res;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int dividend, int divisor)
{
	return divide(dividend,divisor);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/divide-two-integers/tests.txt";
}

