
//////////////////////////////////////////////////////////////////////////
//vector<vector<int>> merge(vector<vector<int>>& intervals) {
//	auto f = [](const vector<int> &vec1, const vector<int> &vec2)
//	{
//		return vec1[0] < vec2[0];
//	};
//
//	sort(intervals.begin(), intervals.end(), f);
//
//	int i = 0;
//	for (int j = 0; j < intervals.size(); ++i)
//	{
//		if (i != j)
//		{
//			intervals[i] = intervals[j];
//		}
//
//		++j;
//		for (; j < intervals.size(); ++j)
//		{
//			if (intervals[i][1] >= intervals[j][0])
//			{
//				intervals[i][1] = max(intervals[i][1], intervals[j][1]);
//			}
//			else
//			{
//				break;
//			}
//		}
//
//	}
//
//	intervals.resize(i);
//	return intervals;
//}


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	auto vector_earse = [](vector<vector<int>> &a, int n)
	{
		for (int i = n; i < a.size() - 1; i++) a[i] = a[i + 1];
		if (a.size() > 0 && a.size() > n) a.pop_back();
	};

	vector<vector<int>> ans;
	for (int i = 0; i < intervals.size(); i++)
	{
		auto n = intervals[i];
		ans.push_back(n);
		if (ans.size() == 1) continue;
		int repeat = ans.size() - 1;
		for (int j = ans.size() - 2; j >= 0; j--)
		{
			auto &m = ans[j];
			if (n[0] <= m[1] && n[1] >= m[0])
			{
				m[0] = min(n[0], m[0]);
				m[1] = max(n[1], m[1]);
				vector_earse(ans, repeat);
				repeat = j;
				n = m;
			}
		}
	}

	return ans;
}


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& intervals)
{
	return merge(intervals);
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
	return "../../problems/merge-intervals/tests.txt";
}

