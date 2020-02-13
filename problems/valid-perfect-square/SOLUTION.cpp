


//////////////////////////////////////////////////////////////////////////
bool isPerfectSquare(int num)
{
	if (num == 0) return true;
	if (num == 1) return true;
	long long low = 1;
	long long high = num;
	while (low < high)
	{
		long long mid = low + (high - low) / 2;
		if (mid * mid == num) return true;
		else if (mid * mid < num) low = mid + 1;
		else high = mid;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(int num)
{
	return isPerfectSquare(num);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

