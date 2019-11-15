


//////////////////////////////////////////////////////////////////////////
int mySqrt(int x)
{
	if (x == 0) return 0;
	if (x < 4) return 1;
	long long low = 1;
	long long high = x;
	while (low < high)
	{
		long long mid = low + (high - low) / 2;
		if (mid * mid <= x) low = mid + 1;
		else high = mid;
	}
	return low - 1;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int x)
{
	return mySqrt(x);
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
	return "../../problems/sqrtx/tests.txt";
}

