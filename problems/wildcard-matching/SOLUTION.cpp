


//////////////////////////////////////////////////////////////////////////
bool isMatch(string s, string p) 
{
	int si = 0;
	int pi = 0;
	int sStar = -1; 
	int pStar = -1;

	while (si < s.size())
	{
		if (pi < p.size() && (s[si] == p[pi] || p[pi] == '?')) 
		{
			++si, ++pi;
		}
		else if (pi < p.size() && p[pi] == '*')
		{
			sStar = si;
			pStar = pi++;
		}
		else if (sStar >= 0) 
		{
			si = ++sStar;
			pi = pStar + 1;
		}
		else
		{
			return false;
		}
	}

	while (pi < p.size() && p[pi] == '*')
	{
		++pi;
	}

	return pi == p.size();
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
	return "../../problems/wildcard-matching/tests.txt";
}

