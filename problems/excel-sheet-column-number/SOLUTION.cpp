


//////////////////////////////////////////////////////////////////////////
int titleToNumber(string s)
{
	int res = 0;
	double i = 1;
	while (!s.empty())
	{
		res += (s.back() - 'A' + 1) * i;
		s.pop_back();
		i *= 26;
	}
	return res;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	return titleToNumber(s);
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

