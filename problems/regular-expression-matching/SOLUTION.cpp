


//////////////////////////////////////////////////////////////////////////
bool isMatch(string& s, string& p, int si, int pi, int ti = -1)
{
	if (si == s.size() && pi == p.size()) return true;
	if (pi >= p.size()) return false;
	if (si >= s.size())
	{
		while (pi < p.size())
		{
			if (pi + 1 == p.size() || p[pi + 1] != '*') return false;
			pi += 2;
		}
		return true;
	}

	if (ti != -1)
	{
		if (p[ti] != '.' && s[si] != p[ti]) return false;
		return isMatch(s, p, si + 1, pi + 1);
	}

	if (pi + 1 != p.size() && p[pi + 1] == '*')
	{
		if (isMatch(s, p, si, pi + 2)) return true;
		for (int i = 1; i <= s.size() - si; i++)
		{
			if (p[pi] != '.' && s[si + i - 1] != p[pi]) break;
			if (isMatch(s, p, si + i - 1, pi + 1, pi)) return true;
		}
		return false;
	}

	if (isalpha(p[pi]))
	{
		if (s[si] != p[pi]) return false;
		return isMatch(s, p, si + 1, pi + 1);
	}

	if (p[pi] == '.')
	{
		return isMatch(s, p, si + 1, pi + 1);
	}

	return false;
}

bool isMatch(string s, string p) 
{
	return isMatch(s, p, 0, 0);
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s, string p)
{
	cout << s << endl << p << endl;
	return isMatch(s,p);
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
	return "../../problems/regular-expression-matching/tests.txt";
}

