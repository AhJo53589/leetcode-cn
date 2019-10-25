//////////////////////////////////////////////////////////////////////////
vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) 
{
	sort(slots1.begin(), slots1.end());
	sort(slots2.begin(), slots2.end());

	size_t i = 0, j = 0;
	while (i < slots1.size() && j < slots2.size())
	{
		int start = max(slots1[i][0], slots2[j][0]);
		int end = min(slots1[i][1], slots2[j][1]);
		if (end - start >= duration)
		{
			return { start, start + duration };
		}
		if (slots1[i][1] < slots2[j][1])
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	return {};
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) 
{
	return minAvailableDuration(slots1, slots2, duration);
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
	return "../../problems/meeting-scheduler/tests.txt";
}


