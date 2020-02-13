
//////////////////////////////////////////////////////////////////////////
//int maxEnvelopes(vector<vector<int>>& envelopes) 
//{
//	if (envelopes.size() <= 1) return envelopes.size();
//
//	sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) 
//	{
//		return a[0] < b[0] || a[0] == b[0] && a[1] > b[1];
//	});
//
//	int ans = 0;
//	vector<int> vec(envelopes.size(), INT_MAX);
//	for (auto &e : envelopes) 
//	{
//		auto it = lower_bound(vec.begin(), vec.end(), e[1]);
//		*it = e[1];
//		ans = max(ans, int(it - vec.begin()));
//	}
//	return ans + 1;
//}

//////////////////////////////////////////////////////////////////////////
//int maxEnvelopes(vector<vector<int>>& envelopes)
//{
//	if (envelopes.size() <= 1) return envelopes.size();
//
//	sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b)
//	{
//		if (a[0] == b[0]) return a[1] > b[1];
//		return a[0] < b[0];
//	});
//
//	int ans = 0;
//	vector<int> vec(envelopes.size(), INT_MAX);
//	for (auto &e : envelopes)
//	{
//		int low = 0;
//		int high = envelopes.size() - 1;
//		while (high > low)
//		{
//			int mid = low + (high - low) / 2;
//			if (vec[mid] >= e[1]) high = mid;
//			else low = mid + 1;
//		}
//
//		vec[low] = e[1];
//		ans = max(ans, low);
//	}
//	return ans + 1;
//}


//////////////////////////////////////////////////////////////////////////
int maxEnvelopes(vector<vector<int>>& envelopes)
{
	if (envelopes.size() <= 1) return envelopes.size();

	sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b)
	{
		if (a[0] == b[0]) return a[1] > b[1];
		return a[0] < b[0];
	});

	vector<int> vec;
	for (int i = 0; i < envelopes.size(); i++)
	{
		int h = envelopes[i][1];
		if (vec.empty() || h > vec.back())
		{
			vec.push_back(h);
		}

		for (int j = 0; j < vec.size(); j++)
		{
			if (h <= vec[j])
			{
				vec[j] = h;
				break;
			}
		}
	}

	return vec.size();
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& envelopes)
{
	return maxEnvelopes(envelopes);
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

