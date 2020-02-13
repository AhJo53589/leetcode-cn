


//////////////////////////////////////////////////////////////////////////
int lengthOfLongestSubstring(string s)
{
	int len = 0;
	unordered_set<char> set;
	for (int i = 0; i < s.size(); i++)
	{
		int len_temp = 0;
		set.clear();
		for (int j = i; j < s.size(); j++)
		{
			if (!set.count(s[j]))
			{
				set.insert(s[j]);
				len_temp++;
				continue;
			}
			break;
		}
		len = max(len, len_temp);
	}
	return len;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	return lengthOfLongestSubstring(s);
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

