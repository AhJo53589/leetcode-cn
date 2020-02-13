
//////////////////////////////////////////////////////////////////////////
//bool wordPattern(string pattern, string str) 
//{
//	map<char, int> m1;
//	map<string, int> m2;
//	int i = 0, n = pattern.size();
//	istringstream in(str);
//
//	for (string word; in >> word; i++)
//	{
//		if (i == n || m1[pattern[i]] != m2[word]) return false;
//		m1[pattern[i]] = m2[word] = i + 1;
//	}
//
//	return i == n;
//}

//////////////////////////////////////////////////////////////////////////
bool wordPattern(string pattern, string str)
{
	unordered_set<string> s;
	unordered_map<char, string> m;
	vector<string> vec;
	istringstream ss(str);
	string item;
	char delim = ' ';
	while (getline(ss, item, delim))
	{
		vec.push_back(item);
	}
	if (pattern.size() != vec.size()) return false;
	for (auto i = 0; i < pattern.size(); i++)
	{
		if (m.count(pattern[i]) != 0)
		{
			if (m[pattern[i]] != vec[i]) return false;
		}
		else
		{
			if (s.count(vec[i]) != 0) return false;
			m[pattern[i]] = vec[i];
			s.insert(vec[i]);
		}
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string pattern, string str)
{
	return wordPattern(pattern,str);
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

