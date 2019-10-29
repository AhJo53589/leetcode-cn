


//////////////////////////////////////////////////////////////////////////
bool canWinNim(int n)
{
	return n % 4 != 0;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(int n)
{
	return canWinNim(n);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
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
	return "../../problems/nim-game/tests.txt";
}

