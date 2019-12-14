


//////////////////////////////////////////////////////////////////////////
int removeCoveredIntervals(vector<vector<int>>& intervals) 
{
	sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
		{
			if (a[0] == b[0])
			{
				return b[1] < a[1];
			}
			return (a[0] < b[0]);
		});

	for (auto v : intervals)
	{
		cout << v[0] << "," << v[1] << endl;
	}
	int cnt = 0;
	for (size_t i = 1; i < intervals.size(); i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (intervals[i][0] >= intervals[j][0]
				&& intervals[i][1] <= intervals[j][1])
			{
				cnt++;
				break;
			}
		}
	}
	return intervals.size() - cnt;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& intervals)
{
	return removeCoveredIntervals(intervals);
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
	return "../../problems/remove-covered-intervals/tests.txt";
}

