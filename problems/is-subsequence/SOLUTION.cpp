


//////////////////////////////////////////////////////////////////////////
bool isSubsequence(string s, string t) 
{
	if (s == "") return true;
	if (t == "") return false;
	size_t j = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		while (true)
		{
			if (j == t.size()) return false;
			if (s[i] == t[j++]) break;
		}
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s, string t)
{
	return isSubsequence(s,t);
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
	return "../../problems/is-subsequence/tests.txt";
}

