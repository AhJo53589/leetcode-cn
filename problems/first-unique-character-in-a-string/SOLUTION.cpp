


//////////////////////////////////////////////////////////////////////////
int firstUniqChar(string s)
{
	vector<int> charCount(26, 0);
	for (int i = 0; i < s.size(); i++)
	{
		charCount[s[i] - 'a'] ++;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (charCount[s[i] - 'a'] == 1)
		{
			return i;
		}
	}
	return -1;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	return firstUniqChar(s);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

