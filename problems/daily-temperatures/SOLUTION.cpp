


//////////////////////////////////////////////////////////////////////////
vector<int> dailyTemperatures(vector<int>& T)
{
	vector<int> days(T.size());
	stack<int> s;
	for (int i = 0; i < T.size(); i++)
	{
		while (!s.empty() && T[s.top()] < T[i])
		{
			days[s.top()] = i - s.top();
			s.pop();
		}
		s.push(i);
	}
	return days;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& T)
{
	return dailyTemperatures(T);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

