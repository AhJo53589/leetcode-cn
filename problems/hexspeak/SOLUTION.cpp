


//////////////////////////////////////////////////////////////////////////
char getCh(char c) 
{
	if (c == 0) return 'O';
	if (c == 1) return 'I';
	if (c < 10) return -1;
	return c - 10 + 'A';
}

string toHexspeak(string num) 
{
	long long n = stoll(num);
	string s;
	while (n) 
	{
		char c = getCh(n % 16);
		if (c == -1) return "ERROR";
		s.push_back(c);
		n /= 16;
	}
	reverse(s.begin(), s.end());
	return s;
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(string num)
{
	return toHexspeak(num);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
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
	return "../../problems/hexspeak/tests.txt";
}

