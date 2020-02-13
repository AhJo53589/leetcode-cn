


//////////////////////////////////////////////////////////////////////////
int strStr(string haystack, string needle)
{
	if (needle == "") return 0;

	for (int i = 0; i < haystack.size(); i++)
	{
		for (int j = 0; j < needle.size(); j++)
		{
			if (i + j == haystack.size()) return -1;
			if (haystack[i + j] != needle[j]) break;
			if (j == needle.size() - 1) return i;
		}
	}
	return -1;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string haystack, string needle)
{
	return strStr(haystack,needle);
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

