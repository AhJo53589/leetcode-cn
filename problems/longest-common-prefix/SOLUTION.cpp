


//////////////////////////////////////////////////////////////////////////
string longestCommonPrefix(vector<string>& strs)
{
	if (strs.size() == 0) return "";
	if (strs.size() == 1) return strs[0];
	int i = 0;
	while (true)
	{
		for (int j = 1; j < strs.size(); j++)
		{
			if ((i == strs[0].size()) || (i == strs[j].size()) || (strs[0][i] != strs[j][i]))
			{
				if (i == 0) return "";
				return strs[0].substr(0, i);
			}
		}
		++i;
	}
	return "";
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<string>& strs)
{
	return longestCommonPrefix(strs);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

