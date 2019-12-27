


//////////////////////////////////////////////////////////////////////////
bool check(string& s, int beg, int end)
{
	if (beg > end) return false;
	while (beg < end)
	{
		if (s[beg++] != s[end--]) return false;
	}
	return true;
}

void partition(string& s, int beg, vector<string> part, set<vector<string>>& ans)
{
	for (int i = beg; i < s.size(); i++)
	{
		string sub;
		for (int j = i; j < s.size(); j++)
		{
			sub += s[j];
			if (!check(s, i, j)) continue;
			part.push_back(sub);
			partition(s, j + 1, part, ans);
			if (j == s.size() - 1)
			{
				ans.insert(part);
			}
			part.pop_back();
		}
		part.push_back({ s[i] });
	}
}

vector<vector<string>> partition(string s) 
{
	set<vector<string>> ans;
	vector<string> part;
	partition(s, 0, part, ans);

	vector<vector<string>> ret(ans.begin(), ans.end());
	return ret;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<string>> _solution_run(string s)
{
	return partition(s);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<string>> _solution_custom(TestCases &tc)
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

