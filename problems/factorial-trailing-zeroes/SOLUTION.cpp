


//////////////////////////////////////////////////////////////////////////
int trailingZeroes(int n)
{
	int res = 0;
	while (n)
	{
		res += n / 5;
		n /= 5;
	}
	return res;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	return trailingZeroes(n);
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
	return "../../problems/factorial-trailing-zeroes/tests.txt";
}

