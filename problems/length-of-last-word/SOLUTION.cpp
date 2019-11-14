
//////////////////////////////////////////////////////////////////////////
//void trimRightTrailingSpaces(string &input)
//{
//	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//		return !isspace(ch);
//	}).base(), input.end());
//}
//
//int lengthOfLastWord(string s)
//{
//	trimRightTrailingSpaces(s);
//	string::size_type p = s.find_last_of(' ');
//	return (p == string::npos) ? s.size() : s.size() - p - 1;
//}

//////////////////////////////////////////////////////////////////////////
//int lengthOfLastWord(string s)
//{
//	reverse(s.begin(), s.end());
//	istringstream ss(s);
//	string word;
//	while (ss >> word)
//	{
//		return word.size();
//	}
//	return 0;
//}


//////////////////////////////////////////////////////////////////////////
int lengthOfLastWord(string s)
{
	while (s.back() == ' ')
	{
		s.pop_back();
	}
	for (size_t i = s.size() - 1; i < s.size(); i--)
	{
		if (s[i] == ' ')
		{
			return s.size() - i - 1;
		}
	}
	return s.size();
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	return lengthOfLastWord(s);
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
	return "../../problems/length-of-last-word/tests.txt";
}

