


//////////////////////////////////////////////////////////////////////////
int getMoneyAmount(int n) 
{
	if (n == 1) return 0;
	if (n == 2) return 1;
	//if (n == 3) return 2;
	//if (n == 4) return 4;
	//if (n == 5) return 6;

	int start = (n & 1) ? 2 : 1;
	int end = n - 1;
	int fac = 2;
	int cnt = (end - start) / fac + 1;
	int sum = (start + end) * cnt / 2;

	return (start + end) * cnt / 2;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	return getMoneyAmount(n);
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
	return "../../problems/_test_0/tests.txt";
}

