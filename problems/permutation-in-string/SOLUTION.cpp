

//////////////////////////////////////////////////////////////////////////
bool checkInclusion(string s1, string s2)
{
	int cc_s1[26] = { 0 };
	for (auto &c : s1)
	{
		cc_s1[c - 'a']++;
	}

	int cc_s2[26] = { 0 };
	size_t left = 0;
	for (size_t i = 0; i < s2.size(); i++)
	{
		int t = s2[i] - 'a';
		cc_s2[t]++;
		if (cc_s2[t] == cc_s1[t])
		{
			bool bFlag = true;
			for (size_t j = 0; j < 26; j++)
			{
				if (cc_s2[j] != cc_s1[j])
				{
					bFlag = false;
					break;
				}
			}
			if (bFlag) return true;
		}
		else if (cc_s2[t] > cc_s1[t])
		{
			for (size_t j = left; j <= i; j++)
			{
				int t2 = s2[j] - 'a';
				cc_s2[t2]--;
				left++;
				if (s2[j] == s2[i]) break;
			}
		}
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s1, string s2)
{
	return checkInclusion(s1,s2);
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

