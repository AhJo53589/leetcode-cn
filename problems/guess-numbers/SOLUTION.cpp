


//////////////////////////////////////////////////////////////////////////
int game(vector<int>& guess, vector<int>& answer)
{
	int ans = 0;
	for (size_t i = 0; i < guess.size(); i++)
	{
		ans = (guess[i] == answer[i]) ? ans + 1 : ans;
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& guess, vector<int>& answer)
{
	return game(guess,answer);
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
	return "../../problems/guess-numbers/tests.txt";
}

