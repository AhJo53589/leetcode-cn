


//////////////////////////////////////////////////////////////////////////
string breakPalindrome(string palindrome)
{
	if (palindrome.size() <= 1) return "";
	for (size_t i = 0; i < palindrome.size(); i++)
	{
		if (palindrome[i] == 'a' && i != palindrome.size() - 1) continue;
		if (palindrome.size() % 2 == 1 && i == palindrome.size() / 2) continue;
		palindrome[i] = (palindrome[i] == 'a') ? 'b' : 'a';
		break;
	}
	return palindrome;
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(string palindrome)
{
	return breakPalindrome(palindrome);
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
	return "../../problems/break-a-palindrome/tests.txt";
}

