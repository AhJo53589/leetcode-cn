


//////////////////////////////////////////////////////////////////////////
int minCostToMoveChips(vector<int>& chips) 
{
	int odd = 0;
	for (auto n : chips)
	{
		odd += (n & 1);
	}
	return (odd < chips.size() - odd) ? odd : chips.size() - odd;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& chips)
{
	return minCostToMoveChips(chips);
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
	return "../../problems/play-with-chips/tests.txt";
}

