
//////////////////////////////////////////////////////////////////////////
bool valid(string& s, vector<int>& use)
{
	int st = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!use[i]) continue;
		st += (s[i] == '(');
		st -= (s[i] == ')');
		if (st < 0) return false;
	}
	return (st == 0);
}

vector<string> removeInvalidParentheses(string s) 
{	
	set<string> ans;
	vector<int> use(s.size(), 1);

	for (int k = 0; k < s.size(); k++)
	{
		for (int i = 0; i < s.size(); i++)
		{
			use[i] = (i >= k);
		}

		while (next_permutation(use.begin(), use.end()))
		{
			if (valid(s, use))
			{
				string a;
				for (size_t i = 0; i < s.size(); i++)
				{
					if (!use[i]) continue;
					a += s[i];
				}
				ans.insert(a);

				k = s.size();
			}
		}
	}
	return vector<string>(ans.begin(), ans.end());
}

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(string s)
{
	return removeInvalidParentheses(s);
}

//#define USE_SOLUTION_CUSTOM
//vector<string> _solution_custom(TestCases &tc)
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
	return "../../problems/_test_0/tests.txt";
}

