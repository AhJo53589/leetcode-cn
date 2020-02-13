
unordered_set<int> visited;

//////////////////////////////////////////////////////////////////////////
bool isHappy(int n)
{
	if (visited.count(n)) return false;
	visited.insert(n);

	int s = 0;
	while (n > 0)
	{
		s += pow((n % 10), 2);
		n /= 10;
	}
	if (s == 1) return true;
	return isHappy(s);
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(int n)
{
	return isHappy(n);
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

