


//////////////////////////////////////////////////////////////////////////
void reverseString(vector<char>& s) 
{
	int iLen = s.size();
	for (int i = 0; i < iLen / 2; i++)
	{
		swap(s[i], s[iLen - i - 1]);
	}
}

//////////////////////////////////////////////////////////////////////////
vector<char> _solution_run(vector<char>& s)
{
	reverseString(s);
	return s;
}

//#define USE_SOLUTION_CUSTOM
//void _solution_custom(TestCases &tc)
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
	return "../../problems/reverse-string/tests.txt";
}

