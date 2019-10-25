


//////////////////////////////////////////////////////////////////////////
bool isValid(string str)
{
	stack<char> s;
	for (int i = 0; i < str.size(); i++)
	{
		if (s.empty())
		{
			s.push(str[i]);
			continue;
		}

		if (s.top() != '(' && s.top() != '[' && s.top() != '{') return false;

		if ((s.top() == '(' && str[i] == ')')
			|| (s.top() == '[' && str[i] == ']')
			|| (s.top() == '{' && str[i] == '}'))
		{
			s.pop();
		}
		else
		{
			s.push(str[i]);
		}
	}
	return s.empty();
}


//////////////////////////////////////////////////////////////////////////
bool _solution_run(string str)
{
	return isValid(str);
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
	return "../../problems/valid-parentheses/tests.txt";
}

