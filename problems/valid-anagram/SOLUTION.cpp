


//////////////////////////////////////////////////////////////////////////
bool isAnagram(string s, string t)
{
	if (s.size() != t.size()) return false;

	vector<int> charCount_s(26, 0);
	vector<int> charCount_t(26, 0);
	for (int i = 0; i < s.size(); i++)
	{
		charCount_s[s[i] - 'a'] ++;
		charCount_t[t[i] - 'a'] ++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (charCount_s[i] != charCount_t[i])
		{
			return false;
		}
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s, string t)
{
	return isAnagram(s,t);
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
	return "../../problems/valid-anagram/tests.txt";
}

