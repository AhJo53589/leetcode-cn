
//////////////////////////////////////////////////////////////////////////
bool isIsomorphic(string s, string t)
{
	unordered_map<char, char> m;
	unordered_set<char> c;	
	for (int i = 0; i < s.size(); i++)
	{
		if (m.count(s[i]))
		{
			if (m[s[i]] != t[i]) return false;
		}
		else
		{
			if (c.count(t[i])) return false;
			m[s[i]] = t[i];
			c.insert(t[i]);
		}
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s, string t)
{
	return isIsomorphic(s,t);
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
	return "../../problems/isomorphic-strings/tests.txt";
}

