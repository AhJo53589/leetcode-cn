


//////////////////////////////////////////////////////////////////////////
int findPoisonedDuration(vector<int>& timeSeries, int duration) 
{
	if (timeSeries.empty()) return 0;

	int ans = 0;
	for (size_t i = 1; i < timeSeries.size(); i++)
	{
		ans += min(timeSeries[i] - timeSeries[i - 1], duration);
	}
	return ans += duration;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& timeSeries, int duration)
{
	return findPoisonedDuration(timeSeries,duration);
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

