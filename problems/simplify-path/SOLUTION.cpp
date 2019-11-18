


//////////////////////////////////////////////////////////////////////////
string simplifyPath(string &path)
{
	for (size_t i = path.size(); i > 0; )
	{
		i--;
		path[i] = (path[i] == '/' ? ' ' : path[i]);
	}
	stringstream istr(path);
	vector<string> vs;
	string str;
	while (istr >> str)
	{
		if (str == ".") continue;
		if (str != "..") vs.push_back(str);
		else if (vs.size()) vs.pop_back();
	}
	str.clear();
	for (auto &s : vs)
	{
		str.append("/" + s);
	}
	return str.empty() ? "/" : str;
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(string &path)
{
	return simplifyPath(path);
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
	return "../../problems/simplify-path/tests.txt";
}

