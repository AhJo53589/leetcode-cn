


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
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/excel-sheet-column-number/tests.txt";
}

