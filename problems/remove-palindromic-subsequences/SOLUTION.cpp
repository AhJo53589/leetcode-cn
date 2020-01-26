


//////////////////////////////////////////////////////////////////////////
bool valid(string& s, int start, int end)
{
	if (start >= end) return false;

	for (int i = 0; i < end - start; i++)
	{
		int a = start + i;
		int b = end - i;
		if (a >= b) break;
		if (s[a] != s[b]) return false;
	}
	return true;
}

void deleteString(string& s, int start, int end)
{
	string a = s.substr(0, start);
	string b = s.substr(end + 1, s.size() - end - 1);
	s = a + b;
}

int removePalindromeSub(string s) 
{
	if (s.size() == 0) return 0;
	if (s.size() == 1) return 1;
	if (valid(s, 0, s.size() - 1)) return 1;
	return 2;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	return removePalindromeSub(s);
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
	return "../../problems/remove-palindromic-subsequences/tests.txt";
}

