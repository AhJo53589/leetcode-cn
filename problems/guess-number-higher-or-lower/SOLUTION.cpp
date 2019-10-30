
static int g_n = 0;
int guess(int num)
{
	if (num == g_n) return 0;
	return (num < g_n) ? 1 : -1;
}

//////////////////////////////////////////////////////////////////////////
int guessNumber(int n)
{
	int low = 0;
	int high = n;
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		int guessResult = guess(mid);
		if (guessResult == 0) return mid;
		else if (guessResult == 1) low = mid + 1;
		else high = mid;
	}
	return low;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	return guessNumber(n);
}

#define USE_SOLUTION_CUSTOM
int _solution_custom(TestCases &tc)
{
	int n(tc.get<int>());
	g_n = tc.get<int>();
	return guessNumber(n);
}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/guess-number-higher-or-lower/tests.txt";
}

