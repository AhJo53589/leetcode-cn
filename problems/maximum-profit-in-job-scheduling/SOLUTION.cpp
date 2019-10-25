//////////////////////////////////////////////////////////////////////////
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int> startTime, vector<int> endTime, vector<int> profit)
{
	return jobScheduling(startTime, endTime, profit);
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
	return "../../problems/maximum-profit-in-job-scheduling/tests.txt";
}


