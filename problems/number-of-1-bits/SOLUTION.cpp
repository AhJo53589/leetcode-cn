


//////////////////////////////////////////////////////////////////////////
int hammingWeight(uint32_t n)
{
	int sum = 0;
	while (n != 0)
	{
		n &= (n - 1);
		sum++;
	}
	return sum;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(uint32_t n)
{
	return hammingWeight(n);
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
	return "../../problems/number-of-1-bits/tests.txt";
}

