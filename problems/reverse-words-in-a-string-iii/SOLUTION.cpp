


//////////////////////////////////////////////////////////////////////////
string reverseWords(string s)
{
	string str;
	string sub;
	int iBegin = 0;
	int iEnd = 0;

	s += " ";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ') continue;
		for (int j = i - 1; j >= iBegin; j--)
		{
			sub += s[j];
		}
		str += sub;
		if (i != s.size() - 1)
		{
			iBegin = i + 1;
			str += " ";
			sub.clear();
		}
	}
	return str;
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
	return reverseWords(s);
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
	return "../../problems/reverse-words-in-a-string-iii/tests.txt";
}

