


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) 
{
	vector<vector<int>> ans;
	for (auto in : intervals)
	{
		if (in[1] < toBeRemoved[0] || in[0] > toBeRemoved[1])
		{
			ans.push_back(in);
			continue;
		}

		if (in[0] < toBeRemoved[0])
		{
			ans.push_back({ in[0], toBeRemoved[0] });
		}
		if (in[1] > toBeRemoved[1])
		{
			ans.push_back({ toBeRemoved[1], in[1] });
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& intervals, vector<int>& toBeRemoved)
{
	return removeInterval(intervals,toBeRemoved);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
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
	return "../../problems/remove-interval/tests.txt";
}

