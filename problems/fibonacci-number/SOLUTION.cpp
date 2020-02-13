
unordered_map<int, int> cache;

//////////////////////////////////////////////////////////////////////////
int fib(int N)
{
	if (cache.count(N)) return cache[N];

	if (N == 0) return 0;
	if (N == 1) return 1;
	return fib(N - 1) + fib(N - 2);
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int N)
{
	return fib(N);
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

