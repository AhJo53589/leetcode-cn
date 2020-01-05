


//////////////////////////////////////////////////////////////////////////
void checkAndCut(string &s)
{
	int l = 0;
	int r = s.size() - 1;
	while (l < r)
	{
		if (s[l] != s[r]) break;
		l++;
		r--;
	}
	if (l < r)
	{
		s = s.substr(l, r - l + 1);
	}
	else
	{
		s.clear();
	}
}

int minInsertions(string s) 
{
	queue<pair<string, int>> que;
	que.push({s, 0});

	while (!que.empty())
	{
		auto q = que.front();
		que.pop();

		string str = q.first;
		checkAndCut(str);
		if (str.size() == 0) return q.second;

		que.push({ str[str.size() - 1] + str, q.second + 1 });
		que.push({ str + str[0], q.second + 1 });
	}

	return s.size() - 1;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	return minInsertions(s);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
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

