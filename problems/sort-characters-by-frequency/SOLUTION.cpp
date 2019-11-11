


//////////////////////////////////////////////////////////////////////////
string frequencySort(string s)
{
	auto f_cmp = [](const pair<char, int> &a, const pair<char, int> &b) { return a.second > b.second; };
	auto f_sort = [f_cmp](map<char, int> &_m, vector<pair<char, int>> &_v)
	{
		for (auto i : _m) _v.push_back(i);
		sort(_v.begin(), _v.end(), f_cmp);
	};

	map<char, int> m;
	for (auto &c : s)m[c]++;
	vector<pair<char, int>> v;
	f_sort(m, v);
	string res;
	for (auto p : v) for (int i = 0; i < p.second; i++) res += p.first;
	return res;
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
	return frequencySort(s);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
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
	return "../../problems/sort-characters-by-frequency/tests.txt";
}

