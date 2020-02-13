
char getChar(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return c - 'A' + 'a';
	}
	else if (c >= 'a' && c <= 'z')
	{
		return c;
	}
	else if (c >= '0' && c <= '9')
	{
		return c;
	}
	return NULL;
}

string getCleanString(string s)
{
	string t;
	for (int i = 0; i < s.size(); i++)
	{
		char c = getChar(s[i]);
		if (c != NULL)
		{
			t.push_back(c);
		}
	}
	return t;
}

//////////////////////////////////////////////////////////////////////////
bool isPalindrome(string s)
{
	if (s.size() == 0) return true;

	string t = getCleanString(s);
	int len = t.size();
	for (int i = 0; i < len / 2; i++)
	{
		if (t[i] != t[len - i - 1])
		{
			return false;
		}
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s)
{
	return isPalindrome(s);
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

