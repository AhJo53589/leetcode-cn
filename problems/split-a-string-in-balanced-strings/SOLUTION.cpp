//////////////////////////////////////////////////////////////////////////
int balancedStringSplit(string s) 
{
	int l = 0;
	int ans = 0;
	for (auto c : s)
	{
		l += (c == 'L') ? 1 : -1;
		ans += (l == 0) ? 1 : 0;
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	return balancedStringSplit(s);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
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
	return "../../problems/split-a-string-in-balanced-strings/tests.txt";
}


