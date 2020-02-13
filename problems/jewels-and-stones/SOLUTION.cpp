


//////////////////////////////////////////////////////////////////////////
int numJewelsInStones(string J, string S)
{
	unordered_set<char> s;
	for (auto c : J) s.insert(c);
	int i = 0;
	for (auto c : S) if (s.count(c)) i++;
	return i;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string J, string S)
{
	return numJewelsInStones(J,S);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

