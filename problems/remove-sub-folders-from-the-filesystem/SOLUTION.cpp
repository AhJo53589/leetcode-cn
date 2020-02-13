//////////////////////////////////////////////////////////////////////////
void check(unordered_set<string> &us, string &s)
{
	string t = "/";
	size_t i = 1;
	while (i < s.size())
	{
		i = s.find('/', i);
		i = (i == s.npos) ? s.size() : i;
		if (us.count(s.substr(0, i)) != 0) return;
		i++;
	}
	us.insert(s);
}

vector<string> removeSubfolders(vector<string>& folder)
{
	sort(folder.begin(), folder.end(), [](string &a, string&b)
	{
		return a.size() < b.size();
	});
	unordered_set<string> us;
	for (auto &s : folder)
	{
		check(us, s);
	}

	vector<string> ans(us.begin(), us.end());
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(vector<string>& folder)
{
	return removeSubfolders(folder);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}


