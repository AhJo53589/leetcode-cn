//////////////////////////////////////////////////////////////////////////
int dieSimulator(int n, vector<int>& rollMax) 
{
	
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<int>& rollMax) 
{
	return dieSimulator(n, rollMax);
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
	return "../../problems/dice-roll-simulation/tests.txt";
}


