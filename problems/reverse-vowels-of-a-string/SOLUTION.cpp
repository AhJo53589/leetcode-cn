


//////////////////////////////////////////////////////////////////////////
string reverseVowels(string s)
{
	int low = 0;
	int high = s.size() - 1;
	while (low < high)
	{
		auto isVowel = [](char c) { unordered_set<char> list = { 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U' }; return list.count(c); };
		while (low < high && !isVowel(s[low])) low++;
		while (low < high && !isVowel(s[high])) high--;
		swap(s[low++], s[high--]);
	}
	return s;
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
	return reverseVowels(s);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

