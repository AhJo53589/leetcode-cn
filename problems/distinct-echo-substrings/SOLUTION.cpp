


//////////////////////////////////////////////////////////////////////////
int distinctEchoSubstrings(string text)
{
	unordered_set<string> ans;
	const char* t = text.c_str();
	for (size_t i = 0; i < text.size(); i++)
	{
		for (size_t j = 1; i + 2 * j <= text.size(); j++)
		{
			if (memcmp(t + i, t + i + j, j) == 0)
			{
				ans.insert(text.substr(i, j));
			}
		}
	}
	return (int)ans.size();
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string text)
{
	return distinctEchoSubstrings(text);
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

