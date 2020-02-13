
//////////////////////////////////////////////////////////////////////////
//int minTaps(int n, vector<int>& ranges)
//{
//	vector<vector<int>> land(n);
//	for (int i = 0; i < ranges.size(); i++)
//	{
//		int l = max(i - ranges[i], 0);
//		int r = min(i + ranges[i], n);
//		if (l == r) continue;
//		for (int j = l; j < r; j++)
//		{
//			land[j].push_back(i);
//		}
//	}
//
//	for (auto& p : land)
//	{
//		if (p.empty()) return -1;
//	}
//
//	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
//	pq.push({ 0, n - 0 });
//
//	while (!pq.empty())
//	{
//		auto q = pq.top();
//		pq.pop();
//
//		int cnt = q[0] + 1;
//		int cur = n - q[1];
//		for (int p : land[cur])
//		{
//			int r = min(p + ranges[p], n);
//			if (r == n) return cnt;
//			pq.push({ cnt, n - r });
//		}
//	}
//	return -1;
//}

//////////////////////////////////////////////////////////////////////////
int minTaps(int n, vector<int>& ranges) 
{
	vector<int> land(n);
	for (int i = 0; i < ranges.size(); i++)
	{
		int l = max(i - ranges[i], 0);
		int r = min(i + ranges[i], n);
		if (l == r) continue;
		for (int j = l; j < r; j++)
		{
			land[j] = max(land[j], r);
		}
	}

	int cnt = 0;
	int cur = 0;
	while (cur < n)
	{
		if (land[cur] == 0) return -1;
		cur = land[cur];
		cnt++;
	}
	return cnt;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<int>& ranges)
{
	return minTaps(n,ranges);
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

